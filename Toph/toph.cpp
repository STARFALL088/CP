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