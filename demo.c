#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYERS 11
#define MAX_NAME_LENGTH 50
#define MAX_OVERS 3
#define BALLS_PER_OVER 6

typedef struct
{
    char name[MAX_NAME_LENGTH];
    char type[MAX_NAME_LENGTH];
    int runs;
    int balls;
    int wickets;
    int catches;
} Player;

typedef struct
{
    char teamName[MAX_NAME_LENGTH];
    Player players[MAX_PLAYERS];
    int totalRuns;
    int totalWickets;
} Team;

typedef struct
{
    char matchName[MAX_NAME_LENGTH];
    Team team1, team2;
    int tossWinner; // 1 for team1, 2 for team2
} Match;

// Function Prototypes
void initializeTeams(Team *t1, Team *t2);
void toss(Match *m);
void simulateMatch(Match *m);
void playOver(Team *batting, Team *bowling, int over);
void displayLiveScore(Team *t);
void saveMatchStats(Match *m);
void delay(int seconds);

int ISUPPER(char c)
{
    return ('A' <= c && c <= 'Z');
}
int ISLOWER(char c)
{
    return ('a' <= c && c <= 'z');
}
int ISDIGIT(char c)
{
    return ('0' <= c && c <= '9');
}

// Function to check if username already exists
int isUsernameTaken(const char *username)
{
    FILE *file = fopen("users.txt", "r");
    if (!file)
        return 0;

    char line[100];
    while (fgets(line, sizeof(line), file))
    {
        char stored_username[50];
        sscanf(line, "%s", stored_username);
        if (strcmp(username, stored_username) == 0)
        {
            fclose(file);
            return 1;
        }
    }
    fclose(file);
    return 0;
}

// Function to validate password strength
int isStrongPassword(const char *password)
{
    int len = strlen(password);
    int hasUpper = 0, hasLower = 0, hasDigit = 0, hasSpecial = 0;

    if (len < 8)
        return 0;

    for (int i = 0; i < len; i++)
    {
        hasUpper += ISUPPER(password[i]);
        hasLower += ISLOWER(password[i]);
        hasDigit += ISDIGIT(password[i]);
        hasSpecial += (!ISDIGIT(password[i]) && !ISLOWER(password[i]) && !ISUPPER(password[i]));

    }
printf("%d %d %d %d",hasDigit,hasSpecial,hasLower,hasUpper);
    return (hasUpper && hasLower && hasDigit && hasSpecial);
}

void sign_up()
{
    char username[50], password[50];

    printf("Enter username: ");
    scanf("%s", username);

    if (isUsernameTaken(username))
    {
        printf("Username already exists!\n");
        return;
    }

    printf("Enter password (min 8 chars, must include uppercase, lowercase, number, special char): ");
    scanf("%s", password);

    if (!isStrongPassword(password))
    {
        printf("Password is not strong enough! Try again\n");
        sign_up();
        return;
    }

    FILE *file = fopen("users.txt", "a");
    if (!file)
    {
        printf("Error opening file!\n");
        return;
    }

    fprintf(file, "%s %s\n", username, password);
    fclose(file);
    printf("Registration successful!\n");
}

void log_in()
{
    char username[50], password[50];
    char stored_username[50], stored_password[50];
    int found = 0;

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    FILE *file = fopen("users.txt", "r");
    if (!file)
    {
        printf("Error opening file!\n");
        return;
    }

    char line[100];
    while (fgets(line, sizeof(line), file))
    {
        sscanf(line, "%s %s", stored_username, stored_password);
        if (strcmp(username, stored_username) == 0 && strcmp(password, stored_password) == 0)
        {
            found = 1;
            break;
        }
    }
    fclose(file);

    if (found)
    {
        printf("Login successful!\n");
    }
    else
    {
        printf("Invalid username or password!\n");
    }
}
// Main Program
int main()
{
    srand(time(0)); // Seed random number generator

    Match match;
    printf("Welcome to Cricket Match Management System!\n");

    strcpy(match.matchName, "Friendly Match");
    printf("choose \n 1.signup 2.login 3.start\n");
    int n;
    scanf("%d", &n);
    if (n == 1)
    {
        sign_up();
    }
    if (n == 2)
    {
        log_in();
    }
    if (n == 3)
    {
        // Initialize teams with predefined names and players
        initializeTeams(&match.team1, &match.team2);

        // Toss
        toss(&match);

        // Match simulation
        simulateMatch(&match);

        // Save match stats
        saveMatchStats(&match);
    }
    return 0;
}

// Function Definitions

void initializeTeams(Team *t1, Team *t2)
{
    // Predefined team names
    strcpy(t1->teamName, "Team Warriors");
    strcpy(t2->teamName, "Team Titans");

    // Predefined player names for Team 1
    char *players1[MAX_PLAYERS] = {
        "Player1", "Player2", "Player3", "Player4", "Player5",
        "Player6", "Player7", "Player8", "Player9", "Player10", "Player11"};
    char *roles1[MAX_PLAYERS] = {
        "Batsman", "Batsman", "Batsman", "Batsman", "Batsman",
        "All-rounder", "All-rounder", "Bowler", "Bowler", "Bowler", "Bowler"};

    // Predefined player names for Team 2
    char *players2[MAX_PLAYERS] = {
        "PlayerA", "PlayerB", "PlayerC", "PlayerD", "PlayerE",
        "PlayerF", "PlayerG", "PlayerH", "PlayerI", "PlayerJ", "PlayerK"};
    char *roles2[MAX_PLAYERS] = {
        "Batsman", "Batsman", "Batsman", "Batsman", "Batsman",
        "All-rounder", "All-rounder", "Bowler", "Bowler", "Bowler", "Bowler"};

    // Assign players to Team 1
    for (int i = 0; i < MAX_PLAYERS; i++)
    {
        strcpy(t1->players[i].name, players1[i]);
        strcpy(t1->players[i].type, roles1[i]);
        t1->players[i].runs = 0;
        t1->players[i].balls = 0;
        t1->players[i].wickets = 0;
        t1->players[i].catches = 0;
    }

    // Assign players to Team 2
    for (int i = 0; i < MAX_PLAYERS; i++)
    {
        strcpy(t2->players[i].name, players2[i]);
        strcpy(t2->players[i].type, roles2[i]);
        t2->players[i].runs = 0;
        t2->players[i].balls = 0;
        t2->players[i].wickets = 0;
        t2->players[i].catches = 0;
    }

    t1->totalRuns = 0;
    t1->totalWickets = 0;
    t2->totalRuns = 0;
    t2->totalWickets = 0;
}

void toss(Match *m)
{
    printf("\nTossing the coin...\n");
    delay(2);
    m->tossWinner = rand() % 2 + 1; // 1 for team1, 2 for team2
    printf("%s won the toss!\n", m->tossWinner == 1 ? m->team1.teamName : m->team2.teamName);
}

void simulateMatch(Match *m)
{
    printf("\n--- Match Begins! ---\n");
    if (m->tossWinner == 1)
    {
        printf("%s will bat first.\n", m->team1.teamName);
        for (int over = 0; over < MAX_OVERS; over++)
        {
            playOver(&m->team1, &m->team2, over);
        }
        printf("\n--- Innings Break ---\n");
        printf("%s's total score: %d/%d\n", m->team1.teamName, m->team1.totalRuns, m->team1.totalWickets);

        for (int over = 0; over < MAX_OVERS; over++)
        {
            playOver(&m->team2, &m->team1, over);
        }
    }
    else
    {
        printf("%s will bat first.\n", m->team2.teamName);
        for (int over = 0; over < MAX_OVERS; over++)
        {
            playOver(&m->team2, &m->team1, over);
        }
        printf("\n--- Innings Break ---\n");
        printf("%s's total score: %d/%d\n", m->team2.teamName, m->team2.totalRuns, m->team2.totalWickets);

        for (int over = 0; over < MAX_OVERS; over++)
        {
            playOver(&m->team1, &m->team2, over);
        }
    }

    // Display match result
    printf("\n--- Match Result ---\n");
    if (m->team1.totalRuns > m->team2.totalRuns)
    {
        printf("%s wins by %d runs!\n", m->team1.teamName, m->team1.totalRuns - m->team2.totalRuns);
    }
    else if (m->team2.totalRuns > m->team1.totalRuns)
    {
        printf("%s wins by %d runs!\n", m->team2.teamName, m->team2.totalRuns - m->team1.totalRuns);
    }
    else
    {
        printf("The match is a tie!\n");
    }
}

void playOver(Team *batting, Team *bowling, int over)
{
    printf("\nOver %d begins...\n", over + 1);
    for (int ball = 0; ball < BALLS_PER_OVER; ball++)
    {
        printf("Press 'n' for next ball: ");
        char next;
        scanf(" %c", &next);

        if (next == 'n')
        {
            int outcome = rand() % 8; // 0-6 runs or a wicket (7)
            if (outcome == 7)
            {
                batting->totalWickets++;
                printf("Wicket! %s lost a player.\n", batting->teamName);
            }
            else
            {
                batting->totalRuns += outcome;
                printf("Runs scored: %d\n", outcome);
            }
            displayLiveScore(batting);
        }
        else
        {
            printf("Invalid input! Try again.\n");
            ball--;
        }

        if (batting->totalWickets >= MAX_PLAYERS - 1)
        {
            printf("%s is all out!\n", batting->teamName);
            return;
        }
    }
}

void displayLiveScore(Team *t)
{
    printf("Live Score: %s - %d/%d\n", t->teamName, t->totalRuns, t->totalWickets);
}

void saveMatchStats(Match *m)
{
    FILE *file = fopen("match_stats.txt", "w");
    if (!file)
    {
        printf("Error saving match stats!\n");
        return;
    }

    fprintf(file, "Match Name: %s\n", m->matchName);
    fprintf(file, "Team 1: %s - %d/%d\n", m->team1.teamName, m->team1.totalRuns, m->team1.totalWickets);
    fprintf(file, "Team 2: %s - %d/%d\n", m->team2.teamName, m->team2.totalRuns, m->team2.totalWickets);
    fclose(file);
    printf("Match stats saved successfully!\n");
}

void delay(int seconds)
{
    int milliSeconds = 1000 * seconds;
    clock_t startTime = clock();
    while (clock() < startTime + milliSeconds)
        ;
}
