
#include "function.h"
void begin()
{
    int choice;

    do
    {
        if(end_of_match==1)break;
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
            if(end_of_match==1)break;
            break;
        case 5: // Exit
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);
}