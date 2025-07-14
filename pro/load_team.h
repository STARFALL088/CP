#include "function.h"



void loadTeamFromFile(Team *team, const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        return; // No team file exists yet
    }

    char type[10];
    char name[20];
    while (fscanf(file, "%s %s", type, name) != EOF)
    {
        if (strcmp(type, "BAT") == 0)
        {
            strcpy(team->batsmen[team->batsmanCount].name, name);
            team->batsmanCount++;
        }
        else if (strcmp(type, "BOWL") == 0)
        {
            strcpy(team->bowlers[team->bowlerCount].name, name);
            team->bowlerCount++;
        }
    }

    fclose(file);
}
