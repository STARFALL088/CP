#include "function.h"

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
            if(end_of_match==1)break;
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
                if(end_of_match==1)break;
                
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