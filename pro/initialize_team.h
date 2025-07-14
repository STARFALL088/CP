#include "function.h"

void initializeTeams(Team teams[])
{
    strcpy(teams[0].name, "Team1");
    strcpy(teams[1].name, "Team2");
    teams[0].batsmanCount = 0;
    teams[0].bowlerCount = 0;
    teams[1].batsmanCount = 0;
    teams[1].bowlerCount = 0;

    loadTeamFromFile(&teams[0], "team1.txt");
    loadTeamFromFile(&teams[1], "team2.txt");
}
