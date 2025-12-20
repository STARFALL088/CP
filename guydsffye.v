// Verilock FPGA Project - Password-Protected Word Display System
// Target: Basys3 FPGA Board
// Simplified version - no debouncing needed

module verilock(
    input wire clk,           // 100MHz system clock
    input wire BTNU,          // Up button
    input wire BTND,          // Down button
    input wire BTNL,          // Left button
    input wire BTNR,          // Right button
    input wire BTNC,          // Center button
    input wire SW0,           // Mode switch (0=looping, 1=infinite)
    output reg [6:0] seg,     // 7-segment cathodes {CG,CF,CE,CD,CC,CB,CA}
    output reg dp,            // Decimal point
    output reg [3:0] an,      // 7-segment anodes
    output reg [15:0] led     // LEDs
);

    // State definitions
    localparam STATE_MENU = 3'b000;
    localparam STATE_SETP_AUTH = 3'b001;
    localparam STATE_SETP_NEW = 3'b010;
    localparam STATE_SETP_DONE = 3'b011;
    localparam STATE_WORD_AUTH = 3'b100;
    localparam STATE_WORD_EDIT = 3'b101;
    localparam STATE_ERROR = 3'b110;
    localparam STATE_SEARCHING = 3'b111;

    // Direction encoding for password (2 bits per button press)
    localparam DIR_UP = 2'b00;
    localparam DIR_DOWN = 2'b01;
    localparam DIR_LEFT = 2'b10;
    localparam DIR_RIGHT = 2'b11;

    // Character encoding
    localparam CHAR_SPACE = 5'd26;
    localparam CHAR_NULL = 5'd27;

    // Clock dividers
    reg [16:0] refresh_counter = 0;
    reg [24:0] blink_counter = 0;
    
    // Control signals
    wire refresh_tick = (refresh_counter == 17'd65000);
    wire blink_state = blink_counter[24];  // ~1.5Hz blink
    reg [1:0] active_digit = 0;

    // Simple button edge detection - NO DEBOUNCING
    reg BTNU_prev = 0, BTND_prev = 0, BTNL_prev = 0, BTNR_prev = 0, BTNC_prev = 0;
    
    wire BTNU_pressed = BTNU && !BTNU_prev;
    wire BTND_pressed = BTND && !BTND_prev;
    wire BTNL_pressed = BTNL && !BTNL_prev;
    wire BTNR_pressed = BTNR && !BTNR_prev;
    wire BTNC_pressed = BTNC && !BTNC_prev;

    // State machine
    reg [2:0] state = STATE_MENU;
    reg [2:0] return_state = STATE_MENU;
    reg menu_selection = 0;
    reg search_direction = 0;  // 0=forward, 1=backward
    
    // Password storage (6 PIN, 2 bits each = 12 bits)
    reg [11:0] password_storage = 12'b00_00_00_00_00_00; // Default: 6x UP
    reg [11:0] password_input_storage = 0;
    reg [2:0] password_input_pos = 0;
    reg [11:0] new_password_storage = 0;
    reg [2:0] new_password_pos = 0;

    // Message storage (512 characters, 5 bits each)
    reg [4:0] message [0:511];
    reg [8:0] cursor_position = 0;
    reg [8:0] viewport_start = 0;
    
    // Search state
    reg [8:0] search_pos = 0;
    reg [9:0] search_count = 0;
    
    // Display buffers
    reg [4:0] display_chars [0:3];
    reg [26:0] state_timer = 0;
    
    // Password checking
    wire password_match = (password_input_storage == password_storage);
    
    // Initialization
    integer i;
    initial begin
        for (i = 0; i < 512; i = i + 1) begin
            message[i] = CHAR_NULL;
        end
    end

    // Helper functions for password bit manipulation
    function [1:0] get_password_bit;
        input [11:0] pwd;
        input [2:0] index;
        begin
            case(index)
                3'd0: get_password_bit = pwd[11:10];
                3'd1: get_password_bit = pwd[9:8];
                3'd2: get_password_bit = pwd[7:6];
                3'd3: get_password_bit = pwd[5:4];
                3'd4: get_password_bit = pwd[3:2];
                3'd5: get_password_bit = pwd[1:0];
                default: get_password_bit = 2'b00;
            endcase
        end
    endfunction

    function [11:0] set_password_bit;
        input [11:0] pwd;
        input [2:0] index;
        input [1:0] value;
        reg [11:0] result;
        begin
            result = pwd;
            case(index)
                3'd0: result[11:10] = value;
                3'd1: result[9:8] = value;
                3'd2: result[7:6] = value;
                3'd3: result[5:4] = value;
                3'd4: result[3:2] = value;
                3'd5: result[1:0] = value;
                default: result = pwd;
            endcase
            set_password_bit = result;
        end
    endfunction

    // Number to 7-segment for counter display (0-6) - ACTIVE LOW
    function [7:0] num_to_seg;
        input [2:0] num;
        begin
            case (num)
                3'd0: num_to_seg = 8'b00000011; // 0
                3'd1: num_to_seg = 8'b10011111; // 1
                3'd2: num_to_seg = 8'b00100101; // 2
                3'd3: num_to_seg = 8'b00001101; // 3
                3'd4: num_to_seg = 8'b10011001; // 4
                3'd5: num_to_seg = 8'b01001001; // 5
                3'd6: num_to_seg = 8'b01000001; // 6
                default: num_to_seg = 8'b11111111;
            endcase
        end
    endfunction

    // Character editing logic
    reg [4:0] next_char, prev_char;
    always @(*) begin
        if (message[cursor_position] == CHAR_NULL)
            next_char = 5'd0;
        else if (message[cursor_position] == CHAR_SPACE)
            next_char = CHAR_NULL;
        else if (message[cursor_position] == 5'd25)
            next_char = CHAR_SPACE;
        else
            next_char = message[cursor_position] + 1;
            
        if (message[cursor_position] == 5'd0)
            prev_char = CHAR_NULL;
        else if (message[cursor_position] == CHAR_NULL)
            prev_char = CHAR_SPACE;
        else if (message[cursor_position] == CHAR_SPACE)
            prev_char = 5'd25;
        else
            prev_char = message[cursor_position] - 1;
    end

    // LED indicator for SW0
    always @(*) begin
        led = 16'b0;
        led[0] = SW0;  // LD0 shows mode
    end

    // Main sequential logic
    always @(posedge clk) begin
        // Clock dividers
        refresh_counter <= refresh_counter + 1;
        blink_counter <= blink_counter + 1;
        
        if (refresh_tick) begin
            refresh_counter <= 0;
            active_digit <= active_digit + 1;
        end
        
        // Button tracking
        BTNU_prev <= BTNU;
        BTND_prev <= BTND;
        BTNL_prev <= BTNL;
        BTNR_prev <= BTNR;
        BTNC_prev <= BTNC;

        // Timer for temporary states
        if (state_timer > 0)
            state_timer <= state_timer - 1;

        case (state)
            STATE_MENU: begin
                if (BTNU_pressed || BTND_pressed)
                    menu_selection <= !menu_selection;
                    
                if (BTNC_pressed) begin
                    if (menu_selection == 0) begin
                        state <= STATE_SETP_AUTH;
                        password_input_pos <= 0;
                        password_input_storage <= 0;
                    end else begin
                        state <= STATE_WORD_AUTH;
                        password_input_pos <= 0;
                        password_input_storage <= 0;
                    end
                end
                
                if (menu_selection == 0) begin
                    display_chars[3] <= 5'd18; // S
                    display_chars[2] <= 5'd4;  // E
                    display_chars[1] <= 5'd19; // T
                    display_chars[0] <= 5'd15; // P
                end else begin
                    display_chars[3] <= 5'd22; // W
                    display_chars[2] <= 5'd14; // O
                    display_chars[1] <= 5'd17; // R
                    display_chars[0] <= 5'd3;  // D
                end
            end

            STATE_SETP_AUTH: begin
                display_chars[3] <= 5'd0;  // A
                display_chars[2] <= 5'd20; // U
                display_chars[1] <= 5'd19; // T
                display_chars[0] <= 5'd28; // Counter placeholder
                
                if (BTNC_pressed && password_input_pos < 6) begin
                    state <= STATE_ERROR;
                    state_timer <= 27'd100000000;
                    password_input_pos <= 0;
                    password_input_storage <= 0;
                end
                else if (BTNU_pressed && password_input_pos < 6) begin
                    password_input_storage <= set_password_bit(password_input_storage, password_input_pos, DIR_UP);
                    password_input_pos <= password_input_pos + 1;
                    if (password_input_pos == 5) begin
                        if (set_password_bit(password_input_storage, 3'd5, DIR_UP) == password_storage) begin
                            state <= STATE_SETP_NEW;
                            new_password_pos <= 0;
                            new_password_storage <= 0;
                        end else begin
                            state <= STATE_ERROR;
                            state_timer <= 27'd100000000;
                            password_input_pos <= 0;
                            password_input_storage <= 0;
                        end
                    end
                end
                else if (BTND_pressed && password_input_pos < 6) begin
                    password_input_storage <= set_password_bit(password_input_storage, password_input_pos, DIR_DOWN);
                    password_input_pos <= password_input_pos + 1;
                    if (password_input_pos == 5) begin
                        if (set_password_bit(password_input_storage, 3'd5, DIR_DOWN) == password_storage) begin
                            state <= STATE_SETP_NEW;
                            new_password_pos <= 0;
                            new_password_storage <= 0;
                        end else begin
                            state <= STATE_ERROR;
                            state_timer <= 27'd100000000;
                            password_input_pos <= 0;
                            password_input_storage <= 0;
                        end
                    end
                end
                else if (BTNL_pressed && password_input_pos < 6) begin
                    password_input_storage <= set_password_bit(password_input_storage, password_input_pos, DIR_LEFT);
                    password_input_pos <= password_input_pos + 1;
                    if (password_input_pos == 5) begin
                        if (set_password_bit(password_input_storage, 3'd5, DIR_LEFT) == password_storage) begin
                            state <= STATE_SETP_NEW;
                            new_password_pos <= 0;
                            new_password_storage <= 0;
                        end else begin
                            state <= STATE_ERROR;
                            state_timer <= 27'd100000000;
                            password_input_pos <= 0;
                            password_input_storage <= 0;
                        end
                    end
                end
                else if (BTNR_pressed && password_input_pos < 6) begin
                    password_input_storage <= set_password_bit(password_input_storage, password_input_pos, DIR_RIGHT);
                    password_input_pos <= password_input_pos + 1;
                    if (password_input_pos == 5) begin
                        if (set_password_bit(password_input_storage, 3'd5, DIR_RIGHT) == password_storage) begin
                            state <= STATE_SETP_NEW;
                            new_password_pos <= 0;
                            new_password_storage <= 0;
                        end else begin
                            state <= STATE_ERROR;
                            state_timer <= 27'd100000000;
                            password_input_pos <= 0;
                            password_input_storage <= 0;
                        end
                    end
                end
            end

            STATE_SETP_NEW: begin
                display_chars[3] <= 5'd13; // N
                display_chars[2] <= 5'd4;  // E
                display_chars[1] <= 5'd22; // W
                display_chars[0] <= 5'd28; // Counter placeholder
                
                if (BTNC_pressed && new_password_pos < 6) begin
                    state <= STATE_ERROR;
                    state_timer <= 27'd100000000;
                    new_password_pos <= 0;
                    new_password_storage <= 0;
                end
                else if (BTNU_pressed && new_password_pos < 6) begin
                    new_password_storage <= set_password_bit(new_password_storage, new_password_pos, DIR_UP);
                    new_password_pos <= new_password_pos + 1;
                    if (new_password_pos == 5) begin
                        password_storage <= set_password_bit(new_password_storage, 3'd5, DIR_UP);
                        state <= STATE_SETP_DONE;
                        state_timer <= 27'd100000000;
                    end
                end
                else if (BTND_pressed && new_password_pos < 6) begin
                    new_password_storage <= set_password_bit(new_password_storage, new_password_pos, DIR_DOWN);
                    new_password_pos <= new_password_pos + 1;
                    if (new_password_pos == 5) begin
                        password_storage <= set_password_bit(new_password_storage, 3'd5, DIR_DOWN);
                        state <= STATE_SETP_DONE;
                        state_timer <= 27'd100000000;
                    end
                end
                else if (BTNL_pressed && new_password_pos < 6) begin
                    new_password_storage <= set_password_bit(new_password_storage, new_password_pos, DIR_LEFT);
                    new_password_pos <= new_password_pos + 1;
                    if (new_password_pos == 5) begin
                        password_storage <= set_password_bit(new_password_storage, 3'd5, DIR_LEFT);
                        state <= STATE_SETP_DONE;
                        state_timer <= 27'd100000000;
                    end
                end
                else if (BTNR_pressed && new_password_pos < 6) begin
                    new_password_storage <= set_password_bit(new_password_storage, new_password_pos, DIR_RIGHT);
                    new_password_pos <= new_password_pos + 1;
                    if (new_password_pos == 5) begin
                        password_storage <= set_password_bit(new_password_storage, 3'd5, DIR_RIGHT);
                        state <= STATE_SETP_DONE;
                        state_timer <= 27'd100000000;
                    end
                end
            end

            STATE_SETP_DONE: begin
                display_chars[3] <= 5'd3;  // D
                display_chars[2] <= 5'd14; // O
                display_chars[1] <= 5'd13; // N
                display_chars[0] <= 5'd4;  // E
                
                if (state_timer == 0) begin
                    state <= STATE_MENU;
                    password_input_pos <= 0;
                    password_input_storage <= 0;
                end
            end

            STATE_WORD_AUTH: begin
                display_chars[3] <= 5'd0;  // A
                display_chars[2] <= 5'd20; // U
                display_chars[1] <= 5'd19; // T
                display_chars[0] <= 5'd28; // Counter placeholder
                
                if (BTNC_pressed && password_input_pos < 6) begin
                    state <= STATE_ERROR;
                    state_timer <= 27'd100000000;
                    password_input_pos <= 0;
                    password_input_storage <= 0;
                end
                else if (BTNUdisplay_chars_pressed && password_input_pos < 6) begin
                    password_input_storage <= set_password_bit(password_input_storage, password_input_pos, DIR_UP);
                    password_input_pos <= password_input_pos + 1;
                    if (password_input_pos == 5) begin
                        if (set_password_bit(password_input_storage, 3'd5, DIR_UP) == password_storage) begin
                            state <= STATE_WORD_EDIT;
                            cursor_position <= 0;
                            viewport_start <= 0;
                        end else begin
                            state <= STATE_ERROR;
                            state_timer <= 27'd100000000;
                            password_input_pos <= 0;
                            password_input_storage <= 0;
                        end
                    end
                end
                else if (BTND_pressed && password_input_pos < 6) begin
                    password_input_storage <= set_password_bit(password_input_storage, password_input_pos, DIR_DOWN);
                    password_input_pos <= password_input_pos + 1;
                    if (password_input_pos == 5) begin
                        if (set_password_bit(password_input_storage, 3'd5, DIR_DOWN) == password_storage) begin
                            state <= STATE_WORD_EDIT;
                            cursor_position <= 0;
                            viewport_start <= 0;
                        end else begin
                            state <= STATE_ERROR;
                            state_timer <= 27'd100000000;
                            password_input_pos <= 0;
                            password_input_storage <= 0;
                        end
                    end
                end
                else if (BTNL_pressed && password_input_pos < 6) begin
                    password_input_storage <= set_password_bit(password_input_storage, password_input_pos, DIR_LEFT);
                    password_input_pos <= password_input_pos + 1;
                    if (password_input_pos == 5) begin
                        if (set_password_bit(password_input_storage, 3'd5, DIR_LEFT) == password_storage) begin
                            state <= STATE_WORD_EDIT;
                            cursor_position <= 0;
                            viewport_start <= 0;
                        end else begin
                            state <= STATE_ERROR;
                            state_timer <= 27'd100000000;
                            password_input_pos <= 0;
                            password_input_storage <= 0;
                        end
                    end
                end
                else if (BTNR_pressed && password_input_pos < 6) begin
                    password_input_storage <= set_password_bit(password_input_storage, password_input_pos, DIR_RIGHT);
                    password_input_pos <= password_input_pos + 1;
                    if (password_input_pos == 5) begin
                        if (set_password_bit(password_input_storage, 3'd5, DIR_RIGHT) == password_storage) begin
                            state <= STATE_WORD_EDIT;
                            cursor_position <= 0;
                            viewport_start <= 0;
                        end else begin
                            state <= STATE_ERROR;
                            state_timer <= 27'd100000000;
                            password_input_pos <= 0;
                            password_input_storage <= 0;
                        end
                    end
                end
            end

            STATE_WORD_EDIT: begin
                if (BTNL_pressed) begin
                    if (SW0 == 1'b0) begin
                        // Looping mode - skip NULL characters going left
                        search_direction <= 1'b1;  // backward
                        search_pos <= (cursor_position == 0) ? 9'd511 : cursor_position - 1;
                        search_count <= 0;
                        return_state <= STATE_WORD_EDIT;
                        state <= STATE_SEARCHING;
                    end else begin
                        // Infinite mode - go to all positions with wrap
                        cursor_position <= (cursor_position == 0) ? 9'd511 : cursor_position - 1;
                    end
                end
                
                if (BTNR_pressed) begin
                    if (SW0 == 1'b0) begin
                        // Looping mode - skip NULL characters going right
                        search_direction <= 1'b0;  // forward
                        search_pos <= (cursor_position == 511) ? 9'd0 : cursor_position + 1;
                        search_count <= 0;
                        return_state <= STATE_WORD_EDIT;
                        state <= STATE_SEARCHING;
                    end else begin
                        // Infinite mode - go to all positions with wrap
                        cursor_position <= (cursor_position == 511) ? 9'd0 : cursor_position + 1;
                    end
                end
                
                if (BTNU_pressed)
                    message[cursor_position] <= next_char;
                
                if (BTND_pressed)

                    message[cursor_position] <= prev_cnexthar;
                
                // Viewport adjustment
                if (cursor_position < viewport_start)
                    viewport_start <= cursor_position;
                else if (cursor_position >= viewport_start + 4)
                    viewport_start <= cursor_position - 3;
                
                display_chars[3] <= message[viewport_start];
                display_chars[2] <= message[viewport_start + 1];
                display_chars[1] <= message[viewport_start + 2];
                display_chars[0] <= message[viewport_start + 3];
                
                if (BTNC_pressed) begin
                    state <= STATE_MENU;
                    password_input_pos <= 0;
                    password_input_storage <= 0;
                end
            end

            STATE_SEARCHING: begin
                // Search for next non-NULL character
                if (message[search_pos] != CHAR_NULL || search_count >= 512) begin
                    // Found non-NULL or searched entire array
                    cursor_position <= search_pos;
                    state <= return_state;
                end else begin
                    // Keep searching
                    search_count <= search_count + 1;
                    if (search_direction == 1'b0) begin
                        // Forward search with wrap
                        search_pos <= (search_pos == 511) ? 9'd0 : search_pos + 1;
                    end else begin
                        // Backward search with wrap
                        search_pos <= (search_pos == 0) ? 9'd511 : search_pos - 1;
                    end
                end
                
                // Keep displaying current viewport while searching
                display_chars[3] <= message[viewport_start];
                display_chars[2] <= message[viewport_start + 1];
                display_chars[1] <= message[viewport_start + 2];
                display_chars[0] <= message[viewport_start + 3];
            end

            STATE_ERROR: begin
                display_chars[3] <= 5'd4;  // E
                display_chars[2] <= 5'd17; // R
                display_chars[1] <= 5'd17; // R
                display_chars[0] <= 5'd17; // R
                
                if (state_timer == 0) begin
                    state <= STATE_MENU;
                    password_input_pos <= 0;
                    password_input_storage <= 0;
                end
            end
            
            default: begin
                state <= STATE_MENU;
            end
        endcase
    end

    // 7-segment decoder - ACTIVE LOW
    function [7:0] char_to_seg;
        input [4:0] char;
        begin
            case (char)
                5'd0:  char_to_seg = 8'b00010001; // A
                5'd1:  char_to_seg = 8'b11000001; // B
                5'd2:  char_to_seg = 8'b01100011; // C
                5'd3:  char_to_seg = 8'b10000101; // D
                5'd4:  char_to_seg = 8'b01100001; // E
                5'd5:  char_to_seg = 8'b01110001; // F
                5'd6:  char_to_seg = 8'b00001001; // G
                5'd7:  char_to_seg = 8'b10010001; // H
                5'd8:  char_to_seg = 8'b10011111; // I
                5'd9:  char_to_seg = 8'b10001111; // J
                5'd10: char_to_seg = 8'b11110001; // K
                5'd11: char_to_seg = 8'b11100011; // L
                5'd12: char_to_seg = 8'b01010111; // M
                5'd13: char_to_seg = 8'b00010011; // N
                5'd14: char_to_seg = 8'b00000011; // O
                5'd15: char_to_seg = 8'b00110001; // P
                5'd16: char_to_seg = 8'b00011001; // Q
                5'd17: char_to_seg = 8'b01110011; // R
                5'd18: char_to_seg = 8'b01001001; // S
                5'd19: char_to_seg = 8'b11100001; // T
                5'd20: char_to_seg = 8'b10000011; // U
                5'd21: char_to_seg = 8'b11000111; // V
                5'd22: char_to_seg = 8'b10101011; // W
                5'd23: char_to_seg = 8'b10011101; // X
                5'd24: char_to_seg = 8'b10001001; // Y
                5'd25: char_to_seg = 8'b00100101; // Z
                5'd26: char_to_seg = 8'b11111110; // SPACE
                5'd28: char_to_seg = 8'b11111111; // Placeholder for counter
                default: char_to_seg = 8'b11111111; // NULL
            endcase
        end
    endfunction

    // Display output
    reg [7:0] current_seg_data;
    reg current_should_blink;
    
    // Display multiplexing
    always @(posedge clk) begin
        case (active_digit)
            2'b00: an <= 4'b1110;
            2'b01: an <= 4'b1101;
            2'b10: an <= 4'b1011;
            2'b11: an <= 4'b0111;
            default: an <= 4'b1111;
        endcase
        
        // Override rightmost digit with counter in password entry states
        if ((state == STATE_SETP_AUTH || state == STATE_SETP_NEW || state == STATE_WORD_AUTH) && active_digit == 2'b00) begin
            if (state == STATE_SETP_AUTH || state == STATE_WORD_AUTH)
                current_seg_data <= num_to_seg(password_input_pos);
            else if (state == STATE_SETP_NEW)
                current_seg_data <= num_to_seg(new_password_pos);
            else
                current_seg_data <= 8'b11111111;
        end else begin
            case (active_digit)
                2'b00: current_seg_data <= char_to_seg(display_chars[0]);
                2'b01: current_seg_data <= char_to_seg(display_chars[1]);
                2'b10: current_seg_data <= char_to_seg(display_chars[2]);
                2'b11: current_seg_data <= char_to_seg(display_chars[3]);
                default: current_seg_data <= 8'b11111111;
            endcase
        end
        
        current_should_blink <= 0;
        if (state == STATE_WORD_EDIT) begin
            case (active_digit)
                2'b00: current_should_blink <= (cursor_position == viewport_start + 3);
                2'b01: current_should_blink <= (cursor_position == viewport_start + 2);
                2'b10: current_should_blink <= (cursor_position == viewport_start + 1);
                2'b11: current_should_blink <= (cursor_position == viewport_start);
                default: current_should_blink <= 0;
            endcase
        end
        
        if (current_should_blink && !blink_state) begin
            seg <= 7'b1111111;
            dp <= 1'b1;
        end else begin
            seg <= current_seg_data[7:1];
            dp <= current_seg_data[0];
        end
    end

endmodule