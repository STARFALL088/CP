#include "function.h"

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