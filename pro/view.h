#include "function.h"



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
