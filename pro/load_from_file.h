#include "function.h"

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