#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_PLAYERS 5
#define MAX_TEAMS 2
#define MAX_OVERS 3
#define USERNAME_LENGTH 20
#define PASSWORD_LENGTH 20
#define MAX_USERS 100

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

// Struct to store player details
typedef struct
{
    char name[20];
    int runs;
    int balls;
    int sixes;
    int fours;
    int is_out;
    float strike_rate;
} Batsman;

typedef struct
{
    char name[20];
    float overs;
    int balls;
    int runs_conceded;
    int wickets;
    float economy;
} Bowler;

// Struct to store team details
typedef struct
{
    char name[20];
    Batsman batsmen[MAX_PLAYERS];
    Bowler bowlers[MAX_PLAYERS];
    int batsmanCount;
    int bowlerCount;
    int totalRuns;
    int totalWickets;
    int total_balls;
    float current_rr;
    float required_rr;
} Team;
Team teams[MAX_TEAMS];

typedef struct
{
    char name[20];
    int points; // Performance points for MoM calculation
    char team[20];
    char role[10]; // "Batsman" or "Bowler"
    union
    {
        struct
        {
            int runs;
            float strike_rate;
        } bat;
        struct
        {
            int wickets;
            float economy;
        } bowl;
    } stats;
} PlayerPerformance;
PlayerPerformance performances[MAX_PLAYERS * 2];
// Struct to store user credentials
typedef struct
{
    char username[USERNAME_LENGTH];
    char password[PASSWORD_LENGTH];
    int teamIndex; // 0 for Team1, 1 for Team2
} User;

User users[MAX_USERS]; // Define the users array globally
int userCount;
int loggedInTeamIndex = -1;
int first_team_batting = 1;
int currently_batting = 0;
int end_of_match = 0;

// Function prototypes
void initializeTeams(Team teams[]);
void simulateMatch(Team teams[]);
int login(int userCount, int *loggedInTeamIndex);
int signup(int *userCount);
void saveUsersToFile(int userCount);
int loadUsersFromFile();
void manageTeam(Team *team);
void saveTeamToFile(Team *team, const char *filename);
void loadTeamFromFile(Team *team, const char *filename);
void displayBattingView(Team *team);
void displayBowlingView(Team *team);
int isStrongPassword(const char *password);
int isUsernameTaken(const char *username);
void viewNextBall(Team team[], const char *filename1, const char *filename2);
void viewCurrentStatus(Team teams[]);
void saveMatchStatsToFile(Team *team, const char *filename);
void begin();
void option();
void winner();

// void current_run_rate(Team teams[]);
void welcome();

int main()
{
    srand(time(0)); // Seed for random number generation
    welcome();

    userCount = loadUsersFromFile();
    initializeTeams(teams);
    begin();
    if (end_of_match == 1)
        return 0;

    return 0;
}
void ManOfTheMatch()
{

    int performance_point = 0;

    // Process batsmen
    for (int t = 0; t < 2; t++)
    {
        for (int i = 0; i < teams[t].batsmanCount; i++)
        {
            strcpy(performances[performance_point].name, teams[t].batsmen[i].name);
            strcpy(performances[performance_point].team, teams[t].name);
            strcpy(performances[performance_point].role, "Batsman");

            // Points calculation for batsmen
            // Basic formula: runs + (strike_rate/10) + (fours*2) + (sixes*3)
            performances[performance_point].points = teams[t].batsmen[i].runs + (int)(teams[t].batsmen[i].strike_rate / 10) + (teams[t].batsmen[i].fours * 2) + (teams[t].batsmen[i].sixes * 3);
            performances[performance_point].stats.bat.runs = teams[t].batsmen[i].runs;
            performances[performance_point].stats.bat.strike_rate = teams[t].batsmen[i].strike_rate;
            performance_point++;
        }
    }
    for (int t = 0; t < 2; t++)
    {
        for (int i = 0; i < teams[t].bowlerCount; i++)
        {
            strcpy(performances[performance_point].name, teams[t].bowlers[i].name);
            strcpy(performances[performance_point].team, teams[t].name);
            strcpy(performances[performance_point].role, "Bowler");

            // Points calculation for bowlers
            // Basic formula: (wickets*20) + (50 - economy*5)
            performances[performance_point].points = (teams[t].bowlers[i].wickets * 20) + (int)(50 - teams[t].bowlers[i].economy * 5);

            performances[performance_point].stats.bowl.wickets = teams[t].bowlers[i].wickets;
            performances[performance_point].stats.bowl.economy = teams[t].bowlers[i].economy;
            performance_point++;
        }
    }

    // Find best performance
    int bestIndex = 0;
    for (int i = 1; i < performance_point; i++)
    {
        if (performances[i].points > performances[bestIndex].points)
        {
            bestIndex = i;
        }
    }

    // Display Man of the Match
    puts("\n==========================================");
    puts("         MAN OF THE MATCH                ");
    puts("==========================================");
    printf("\n%s (%s from %s)\n",
           performances[bestIndex].name,
           performances[bestIndex].role,
           performances[bestIndex].team);

    if (strcmp(performances[bestIndex].role, "Batsman") == 0)
    {
        printf("Runs: %d\nStrike Rate: %.2f\n",
               performances[bestIndex].stats.bat.runs,
               performances[bestIndex].stats.bat.strike_rate);
    }
    else
    {
        printf("Wickets: %d\nEconomy: %.2f\n",
               performances[bestIndex].stats.bowl.wickets,
               performances[bestIndex].stats.bowl.economy);
    }
    puts("==========================================\n");
}

void welcome()
{
    puts(BLUE "****************************************************" RESET);
    puts(BLUE "*            WELCOME TO THE CRICKET SIMULATOR      *" RESET);
    puts(BLUE "****************************************************\n" RESET);
    puts(BLUE "Experience the thrill of a cricket match simulated dynamically!" RESET);
    puts(BLUE "Two teams, Omor Ekushey Hall and Lalon Shah Hall, battle it out!\n" RESET);
}

void winner()
{
    Team winner;
    if (teams[0].totalRuns > teams[1].totalRuns)
        winner = teams[0];
    else if (teams[0].totalRuns == teams[1].totalRuns)
    {
        puts(BLUE "===========================================" RESET);
        puts(BLUE "             CRICKET MATCH RESULT         " RESET);
        puts(BLUE "===========================================" RESET);
        puts(BLUE "Teams: " RESET);
        puts(" ");
        printf(BLUE "        %s  vs  %s\n" RESET, teams[0].name, teams[1].name);
        puts("IT'S A DRAW");
        return;
    }
    else
        winner = teams[1];
    puts(BLUE "===========================================" RESET);
    puts(BLUE "             CRICKET MATCH RESULT         " RESET);
    puts(BLUE "===========================================" RESET);
    puts(BLUE "Teams: " RESET);
    puts(" ");
    printf(BLUE "        %s  vs  %s\n" RESET, teams[0].name, teams[1].name);
    puts(BLUE "-------------------------------------------" RESET);
    puts(BLUE "             WINNER ANNOUNCEMENT        " RESET);
    puts(" ");
    printf(BLUE "               %s \n" RESET, winner.name);
    puts(" ");
    puts(BLUE "===========================================" RESET);
    puts(BLUE "  Congratulations to the winning team!     " RESET);
    puts(BLUE "===========================================" RESET);
    return;
}
void begin()
{
    int choice;

    do
    {
        if (end_of_match == 1)
            break;
        puts(WHITE "1. Login" RESET);
        puts(WHITE "2. Signup" RESET);
        puts(WHITE "3. Manage Team" RESET);
        puts(WHITE "4. Simulate Match" RESET);
        puts(WHITE "5. Exit" RESET);
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1: // Login
            if (login(userCount, &loggedInTeamIndex))
            {
                printf("Login successful! You are managing %s.\n", teams[loggedInTeamIndex].name);
            }
            else
            {
                printf("Login failed. Invalid username or password.\n");
            }
            break;
        case 2: // Signup
            if (signup(&userCount))
            {
                saveUsersToFile(userCount);
                printf("Signup successful! You can now login.\n");
            }
            else
            {
                printf("Signup failed. Username may already exist or password is weak.\n");
            }
            break;
        case 3: // Manage Team
            if (loggedInTeamIndex != -1)
            {
                manageTeam(&teams[loggedInTeamIndex]);
                saveTeamToFile(&teams[loggedInTeamIndex], loggedInTeamIndex == 0 ? "team1.txt" : "team2.txt");
            }
            else
            {
                printf("Please login first.\n");
            }
            break;
        case 4: // Simulate Match

            option();
            if (end_of_match == 1)
                break;
            break;
        case 5: // Exit
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5 || (end_of_match == 0));
}
void option()
{
    if (loggedInTeamIndex != -1)
    {
        if (first_team_batting)
            simulateMatch(teams);
        puts("ok");
        int subChoice;
        do
        {
            if (end_of_match == 1)
                break;
            puts("");
            puts("1. View Next Ball");
            puts("2. View Current Status");
            puts("3. Save Match Stats");
            puts("4. Back");
            printf("Enter your choice: ");

            scanf("%d", &subChoice);

            switch (subChoice)
            {
            case 1:
                viewNextBall(teams, "team1_stats.txt", "team2_stats.txt");
                if (end_of_match == 1)
                    break;

                break;
            case 2:
                viewCurrentStatus(teams);
                break;
            case 3:
                saveMatchStatsToFile(&teams[loggedInTeamIndex], loggedInTeamIndex == 0 ? "team1_stats.txt" : "team2_stats.txt");
                printf("Match stats saved to file.\n");
                break;
            case 4:

                simulateMatch(teams);
                break;
            default:
                printf("Invalid choice. Try again.\n");
            }
        } while (subChoice != 4);
    }
    else
    {
        printf("Please login first.\n");
    }
}
int login(int userCount, int *loggedInTeamIndex)
{
    char username[USERNAME_LENGTH];
    char password[PASSWORD_LENGTH];

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < userCount; i++)
    {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0)
        {
            *loggedInTeamIndex = users[i].teamIndex;
            return 1; // Login successful
        }
    }
    return 0; // Login failed
}

int signup(int *userCount)
{
    char username[USERNAME_LENGTH];
    char password[PASSWORD_LENGTH];
    int teamChoice;

    printf("Enter a new username: ");
    scanf("%s", username);
    printf("Enter a new password: ");
    scanf("%s", password);

    if (!isStrongPassword(password))
    {
        printf("Password is not strong enough.\n It must be at least 8 characters long, contain uppercase, lowercase, digits, and special characters.\n");
        return 0;
    }

    printf("Choose team (1 for Team1, 2 for Team2): ");
    scanf("%d", &teamChoice);

    if (teamChoice < 1 || teamChoice > 2)
    {
        printf("Invalid team choice.\n");
        return 0;
    }

    // Check if username already exists
    if (isUsernameTaken(username))
    {
        return 0; // Signup failed
    }

    // Add new user
    strcpy(users[*userCount].username, username);
    strcpy(users[*userCount].password, password);
    users[*userCount].teamIndex = teamChoice - 1; // 0 for Team1, 1 for Team2
    (*userCount)++;
    return 1; // Signup successful
}

void manageTeam(Team *team)
{
    int choice;
    do
    {
        printf("\nManaging %s\n", team->name);
        printf("1. Add Batsman\n2. Add Bowler\n3. View Squad\n4. Remove Batsman\n5. Remove Bowler 6.Edit \n8. Back\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1: // Add Batsman
            if (team->batsmanCount < MAX_PLAYERS)
            {
                printf("Enter batsman name: ");
                scanf("%s", team->batsmen[team->batsmanCount].name);
                team->batsmen[team->batsmanCount].runs = 0;
                team->batsmen[team->batsmanCount].balls = 0;
                team->batsmen[team->batsmanCount].sixes = 0;
                team->batsmen[team->batsmanCount].fours = 0;
                team->batsmen[team->batsmanCount].is_out = 0;
                team->batsmen[team->batsmanCount].strike_rate = 0.0;
                team->batsmanCount++;
                printf("Batsman added successfully!\n");
            }
            else
            {
                printf("Team is full. Cannot add more batsmen.\n");
            }
            break;
        case 2: // Add Bowler
            if (team->bowlerCount < MAX_PLAYERS)
            {
                printf("Enter bowler name: ");
                scanf("%s", team->bowlers[team->bowlerCount].name);
                team->bowlers[team->bowlerCount].overs = 0.0;
                team->bowlers[team->bowlerCount].runs_conceded = 0;
                team->bowlers[team->bowlerCount].wickets = 0;
                team->bowlers[team->bowlerCount].economy = 0.0;
                team->bowlerCount++;
                printf("Bowler added successfully!\n");
            }
            else
            {
                printf("Team is full. Cannot add more bowlers.\n");
            }
            break;
        case 3: // View Squad
            printf("\n=== %s Squad ===\n", team->name);
            printf("Batsmen:\n");
            for (int i = 0; i < team->batsmanCount; i++)
            {
                printf("%s\n", team->batsmen[i].name);
            }
            printf("Bowlers:\n");
            for (int i = 0; i < team->bowlerCount; i++)
            {
                printf("%s\n", team->bowlers[i].name);
            }
            printf("================\n");
            break;
        case 4: // Remove Batsman
            if (team->batsmanCount > 0)
            {
                printf("Enter batsman name to remove: ");
                char name[20];
                scanf("%s", name);
                int found = 0;
                for (int i = 0; i < team->batsmanCount; i++)
                {
                    if (strcmp(team->batsmen[i].name, name) == 0)
                    {
                        for (int j = i; j < team->batsmanCount - 1; j++)
                        {
                            team->batsmen[j] = team->batsmen[j + 1];
                        }
                        team->batsmanCount--;
                        found = 1;
                        printf("Batsman removed successfully!\n");
                        break;
                    }
                }
                if (!found)
                {
                    printf("Batsman not found.\n");
                }
            }
            else
            {
                printf("No batsmen to remove.\n");
            }
            break;
        case 5: // Remove Bowler
            if (team->bowlerCount > 0)
            {
                printf("Enter bowler name to remove: ");
                char name[20];
                scanf("%s", name);
                int found = 0;
                for (int i = 0; i < team->bowlerCount; i++)
                {
                    if (strcmp(team->bowlers[i].name, name) == 0)
                    {
                        for (int j = i; j < team->bowlerCount - 1; j++)
                        {
                            team->bowlers[j] = team->bowlers[j + 1];
                        }
                        team->bowlerCount--;
                        found = 1;
                        printf("Bowler removed successfully!\n");
                        break;
                    }
                }
                if (!found)
                {
                    printf("Bowler not found.\n");
                }
            }
            else
            {
                printf("No bowlers to remove.\n");
            }
            break;
        case 6: // Back
            break;
        default:
            printf("Invalid choice. Try again.\n");
        }
    } while (choice != 6);
}

void simulateMatch(Team teams[])
{
    printf("\n=== Match Simulation ===\n");
    printf("%s vs %s\n", teams[0].name, teams[1].name);
    teams[currently_batting].totalRuns = 0;
    teams[1 - currently_batting].totalRuns = 0;
    teams[currently_batting].total_balls = 0;
    teams[1 - currently_batting].total_balls = 0;

    teams[currently_batting].current_rr = 0.0;
    teams[1 - currently_batting].current_rr = 0.0;

    teams[currently_batting].required_rr = 0.0;
    teams[1 - currently_batting].required_rr = 0.0;

    // Simulate batting for Team1
    printf("\n%s Batting:\n", teams[0].name);
    for (int i = 0; i < teams[currently_batting].batsmanCount; i++)
    {
        teams[currently_batting].batsmen[i].runs = 0;
        teams[currently_batting].batsmen[i].balls = 0;
        teams[currently_batting].batsmen[i].sixes = 0;
        teams[currently_batting].batsmen[i].fours = 0;
        teams[currently_batting].batsmen[i].is_out = 0;
        teams[currently_batting].batsmen[i].strike_rate = 0.0;

        teams[1 - currently_batting].batsmen[i].runs = 0;
        teams[1 - currently_batting].batsmen[i].balls = 0;
        teams[1 - currently_batting].batsmen[i].sixes = 0;
        teams[1 - currently_batting].batsmen[i].fours = 0;
        teams[1 - currently_batting].batsmen[i].is_out = 0;
        teams[1 - currently_batting].batsmen[i].strike_rate = 0.0;
    }
    displayBattingView(&teams[currently_batting]);

    // Simulate bowling for Team2
    printf("\n%s Bowling:\n", teams[1 - currently_batting].name);
    for (int i = 0; i < teams[1].bowlerCount; i++)
    {
        teams[currently_batting].bowlers[i].overs = 0;
        teams[currently_batting].bowlers[i].runs_conceded = 0;
        teams[currently_batting].bowlers[i].wickets = 0;
        teams[currently_batting].bowlers[i].economy = 0;

        teams[1 - currently_batting].bowlers[i].overs = 0;
        teams[1 - currently_batting].bowlers[i].runs_conceded = 0;
        teams[1 - currently_batting].bowlers[i].wickets = 0;
        teams[1 - currently_batting].bowlers[i].economy = 0;
    }
    displayBowlingView(&teams[1 - currently_batting]);

    printf("Match simulated successfully!\n");
}

void viewNextBall(Team team[], const char *filename1, const char *filename2)
{
    printf("\n=== Next Ball ===\n");
    static int currentBatsmanIndex = 0; // Track the current batsman
    static int currentBowlerIndex = 0;  // Track the current bowler
    static int secondaryBatsmanIndex = 1;

    Batsman *currentBatsman = &team[currently_batting].batsmen[currentBatsmanIndex];
    Bowler *currentBowler = &team[1 - currently_batting].bowlers[currentBowlerIndex];
    int runs = rand() % 7;          // 0-6 runs
    int isOut = (rand() % 10 == 0); // 10% chance of getting out (1 in 10)

    // Update batting stats
    currentBatsman->runs += runs;
    currentBatsman->balls += (runs != 5); // 5 == no ball +4 run
    currentBatsman->fours += (runs == 4 || runs == 5);
    currentBatsman->sixes += (runs == 6);
    currentBatsman->is_out |= isOut;
    team[currently_batting].totalRuns += runs;
    team[currently_batting].total_balls += (runs != 5);
    team[currently_batting].current_rr = (team[currently_batting].totalRuns * 6.0) / team[currently_batting].total_balls;
    currentBatsman->strike_rate = (currentBatsman->runs * 100.0) / currentBatsman->balls;

    // Update bowling stats
    currentBowler->runs_conceded += runs;
    currentBowler->wickets += isOut;
    currentBowler->balls += (runs != 5); // 5 == no ball +4 run
    currentBowler->overs = currentBowler->balls / 6 + (currentBowler->balls % 6) / 10.0;
    currentBowler->economy = (currentBowler->runs_conceded * 6.0) / currentBowler->balls;

    // Calculate required run rate
    int run_needed = team[1 - currently_batting].totalRuns - team[currently_batting].totalRuns;
    int over_remaining = 6 * MAX_OVERS - team[currently_batting].total_balls;
    float rrr = (run_needed * 6.0) / over_remaining;
    team[currently_batting].required_rr = rrr;

    // change bowler
    if (runs == 1 || runs == 3)
    {
        int temp = currentBatsmanIndex;
        currentBatsmanIndex = secondaryBatsmanIndex;
        secondaryBatsmanIndex = temp;
        currentBatsman = &team[currently_batting].batsmen[currentBatsmanIndex];
    }

    // Change bowler and swap batsmen at over end
    if (currentBowler->balls % 6 == 0 && currentBowler->balls > 0)
    {
        currentBowlerIndex++;
        if (currentBowlerIndex >= team[1 - currently_batting].bowlerCount)
        {
            currentBowlerIndex = 0;
        }
        currentBowler = &team[1 - currently_batting].bowlers[currentBowlerIndex];

        // Swap batsmen at over end
        int temp = currentBatsmanIndex;
        currentBatsmanIndex = secondaryBatsmanIndex;
        secondaryBatsmanIndex = temp;
        currentBatsman = &team[currently_batting].batsmen[currentBatsmanIndex];
    }

    // Display updated stats
    printf("Runs scored: %d\n", runs);
    if (isOut || 6 * MAX_OVERS < team[currently_batting].total_balls)
    {
        printf("Wicket! %s is out.\n", currentBatsman->name);
        currentBatsmanIndex++;
        // printf("total balls %d", team[currently_batting].total_balls);
        if ((currentBatsmanIndex >= team[currently_batting].batsmanCount || 6 * MAX_OVERS < team[currently_batting].total_balls) && first_team_batting)
        {
            printf("All batsmen are out or End of overs . Innings over.\n");
            puts("2nd innings is starting");
            first_team_batting = 0;
            currently_batting = 1 - currently_batting;
            currentBatsman = &team[currently_batting].batsmen[currentBatsmanIndex = 0];
            option();

            return;
        }

        currentBatsman = &team[currently_batting].batsmen[currentBatsmanIndex];
    }
    if ((currentBatsmanIndex >= team[currently_batting].batsmanCount || 6 * MAX_OVERS < team[currently_batting].total_balls || team[currently_batting].totalRuns > team[1 - currently_batting].totalRuns) && !first_team_batting)
    {
        winner();
        ManOfTheMatch();
        end_of_match = 1;
        return;
    }
    // first_batting_team indexing problem   :not fixed

    printf("Current Run Rate: %.2f\n", team[currently_batting].current_rr);
    printf("Current Over: %d.%d\n", team[currently_batting].total_balls / 6, team[currently_batting].total_balls % 6);
    printf("Total Runs: %d\n", team[currently_batting].totalRuns);
    if (!first_team_batting)
        printf("Required Run Rate: %.2f\n", rrr);

    // Save updated stats to file
    saveMatchStatsToFile(&team[currently_batting], (currently_batting == 0 ? filename1 : filename2));
    saveMatchStatsToFile(&team[1 - currently_batting], (currently_batting == 0 ? filename2 : filename1));
}

void viewCurrentStatus(Team teams[])
{
    if (loggedInTeamIndex == -1)
    {
        printf("Please login first.\n");
        return;
    }

    int subChoice1;
    do
    {
        printf("\n=== Current Match Status ===\n");
        printf("1. Display Scoreboard\n");
        printf("2. Display Team1 Stats\n");
        printf("3. Display Team2 Stats\n");
        printf("4. Back\n");
        printf("Enter your choice: ");
        scanf("%d", &subChoice1);

        switch (subChoice1)
        {
        case 1: // Display Scoreboard
            printf("\n=== Scoreboard ===\n");
            printf("Batsmen:\n");
            for (int i = 0; i < teams[currently_batting].batsmanCount; i++)
            {
                printf("%s: %d runs, %d balls, %d fours, %d sixes, SR: %.2f\n",
                       teams[currently_batting].batsmen[i].name,
                       teams[currently_batting].batsmen[i].runs,
                       teams[currently_batting].batsmen[i].balls,
                       teams[currently_batting].batsmen[i].fours,
                       teams[currently_batting].batsmen[i].sixes,
                       teams[currently_batting].batsmen[i].strike_rate);
            }
            printf("Bowlers:\n");
            for (int i = 0; i < teams[currently_batting].bowlerCount; i++)
            {
                printf("%s: %.1f overs, %d runs, %d wickets, Econ: %.2f\n",
                       teams[1 - currently_batting].bowlers[i].name,
                       teams[1 - currently_batting].bowlers[i].overs,
                       teams[1 - currently_batting].bowlers[i].runs_conceded,
                       teams[1 - currently_batting].bowlers[i].wickets,
                       teams[1 - currently_batting].bowlers[i].economy);
            }
            break;
        case 2: // Display Team1 Stats
            printf("\n=== Team1 Stats ===\n");
            displayBattingView(&teams[0]);
            displayBowlingView(&teams[0]);
            break;
        case 3: // Display Team2 Stats
            printf("\n=== Team2 Stats ===\n");
            displayBattingView(&teams[1]);
            displayBowlingView(&teams[1]);
            break;
        case 4: // Back
            break;
        default:
            printf("Invalid choice. Try again.\n");
        }
    } while (subChoice1 != 4);
}

void saveMatchStatsToFile(Team *team, const char *filename)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    fprintf(file, "=== %s Batting ===\n", team->name);
    fprintf(file, "NAME\tRUNS\tBALLS\t4s\t6s\tOUT\tSTRIKE_RATE\n");
    for (int i = 0; i < team->batsmanCount; i++)
    {
        fprintf(file, "%s\t%d\t%d\t%d\t%d\t%d\t%.2f\n",
                team->batsmen[i].name,
                team->batsmen[i].runs,
                team->batsmen[i].balls,
                team->batsmen[i].fours,
                team->batsmen[i].sixes,
                team->batsmen[i].is_out,
                team->batsmen[i].strike_rate);
    }

    fprintf(file, "\n=== %s Bowling ===\n", team->name);
    fprintf(file, "NAME\tOVERS\tRUNS\tWICKETS\tECONOMY\n");
    for (int i = 0; i < team->bowlerCount; i++)
    {
        fprintf(file, "%s\t%.1f\t%d\t%d\t%.2f\n",
                team->bowlers[i].name,
                team->bowlers[i].overs,
                team->bowlers[i].runs_conceded,
                team->bowlers[i].wickets,
                team->bowlers[i].economy);
    }

    fclose(file);
}

void saveTeamToFile(Team *team, const char *filename)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    for (int i = 0; i < team->batsmanCount; i++)
    {
        fprintf(file, "BAT %s\n", team->batsmen[i].name);
    }
    for (int i = 0; i < team->bowlerCount; i++)
    {
        fprintf(file, "BOWL %s\n", team->bowlers[i].name);
    }

    fclose(file);
}

void loadTeamFromFile(Team *team, const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        return; // No team file exists yet
    }

    char type[10];
    char name[20];
    while (fscanf(file, "%s %s", type, name) != EOF)
    {
        if (strcmp(type, "BAT") == 0)
        {
            strcpy(team->batsmen[team->batsmanCount].name, name);
            team->batsmanCount++;
        }
        else if (strcmp(type, "BOWL") == 0)
        {
            strcpy(team->bowlers[team->bowlerCount].name, name);
            team->bowlerCount++;
        }
    }

    fclose(file);
}

int isStrongPassword(const char *password)
{
    int len = strlen(password);
    int hasUpper = 0, hasLower = 0, hasDigit = 0, hasSpecial = 0;

    if (len < 8)
        return 0;

    for (int i = 0; i < len; i++)
    {
        if (isupper(password[i]))
            hasUpper = 1;
        if (islower(password[i]))
            hasLower = 1;
        if (isdigit(password[i]))
            hasDigit = 1;
        if (!isalnum(password[i]))
            hasSpecial = 1;
    }

    return (hasUpper && hasLower && hasDigit && hasSpecial);
}

int isUsernameTaken(const char *username)
{
    int userCount = loadUsersFromFile();
    for (int i = 0; i < userCount; i++)
    {
        if (strcmp(users[i].username, username) == 0)
        {
            return 1;
        }
    }
    return 0;
}

int loadUsersFromFile()
{
    FILE *file = fopen("users.txt", "r");
    if (file == NULL)
    {
        return 0; // No users file exists yet
    }

    int userCount = 0;
    while (fscanf(file, "%s %s %d", users[userCount].username, users[userCount].password, &users[userCount].teamIndex) != EOF)
    {
        userCount++;
    }

    fclose(file);
    return userCount;
}

void displayBowlingView(Team *team)
{
    printf("\n=== %s Bowling ===\n", team->name);
    printf("NAME\t\tOVERS\tRUNS\tWICKETS\tECONOMY\n");
    printf("------------------------------------------------\n");
    for (int i = 0; i < team->bowlerCount; i++)
    {
        printf("%s\t\t%.1f\t%d\t%d\t%.2f\n",
               team->bowlers[i].name,
               team->bowlers[i].overs,
               team->bowlers[i].runs_conceded,
               team->bowlers[i].wickets,
               team->bowlers[i].economy);
    }
    printf("\n");
}

void displayBattingView(Team *team)
{
    printf("\n=== %s Batting ===\n", team->name);
    printf("NAME\t\tRUNS\tBALLS\t4s\t6s\tOUT\tSTRIKE_RATE\n");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < team->batsmanCount; i++)
    {
        printf("%s\t\t%d\t%d\t%d\t%d\t%d\t%.2f\n",
               team->batsmen[i].name,
               team->batsmen[i].runs,
               team->batsmen[i].balls,
               team->batsmen[i].fours,
               team->batsmen[i].sixes,
               team->batsmen[i].is_out,
               team->batsmen[i].strike_rate);
    }
    printf("\n");
}

void saveUsersToFile(int userCount)
{
    FILE *file = fopen("users.txt", "w");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    for (int i = 0; i < userCount; i++)
    {
        fprintf(file, "%s %s %d\n", users[i].username, users[i].password, users[i].teamIndex);
    }

    fclose(file);
}

void initializeTeams(Team teams[])
{
    strcpy(teams[0].name, "Team1");
    strcpy(teams[1].name, "Team2");
    teams[0].batsmanCount = 0;
    teams[0].bowlerCount = 0;
    teams[1].batsmanCount = 0;
    teams[1].bowlerCount = 0;

    loadTeamFromFile(&teams[0], "team1.txt");
    loadTeamFromFile(&teams[1], "team2.txt");
}
