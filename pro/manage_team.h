#include "function.h"
void manageTeam(Team *team)
{
    int choice;
    do
    {
        printf("\nManaging %s\n", team->name);
        printf("1. Add Batsman\n2. Add Bowler\n3. View Squad\n4. Remove Batsman\n5. Remove Bowler 6.Back\nEnter your choice: ");
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