#include "function.h"



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
