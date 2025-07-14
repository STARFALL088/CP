#include "function.h"
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
