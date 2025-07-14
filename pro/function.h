// functions.h
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

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
void calculateManOfTheMatch(Team teams[]);
void begin();
void option();
void winner();
void welcome();


#endif // FUNCTIONS_H