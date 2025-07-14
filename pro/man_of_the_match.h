void calculateManOfTheMatch(Team teams[])
{
    PlayerPerformance performances[MAX_PLAYERS * 2];
    int perfCount = 0;

    // Process batsmen
    for (int t = 0; t < 2; t++)
    {
        for (int i = 0; i < teams[t].batsmanCount; i++)
        {
            strcpy(performances[perfCount].name, teams[t].batsmen[i].name);
            strcpy(performances[perfCount].team, teams[t].name);
            strcpy(performances[perfCount].role, "Batsman");

            // Points calculation for batsmen
            // Basic formula: runs + (strike_rate/10) + (fours*2) + (sixes*3)
            performances[perfCount].points = teams[t].batsmen[i].runs +(int)(teams[t].batsmen[i].strike_rate / 10) +(teams[t].batsmen[i].fours * 2) +(teams[t].batsmen[i].sixes * 3);
            performances[perfCount].stats.bat.runs = teams[t].batsmen[i].runs;
            performances[perfCount].stats.bat.strike_rate = teams[t].batsmen[i].strike_rate;
            perfCount++;
        }
    }
    for (int t = 0; t < 2; t++)
    {
        for (int i = 0; i < teams[t].bowlerCount; i++)
        {
            strcpy(performances[perfCount].name, teams[t].bowlers[i].name);
            strcpy(performances[perfCount].team, teams[t].name);
            strcpy(performances[perfCount].role, "Bowler");

            // Points calculation for bowlers
            // Basic formula: (wickets*20) + (50 - economy*5)
            performances[perfCount].points = (teams[t].bowlers[i].wickets * 20) +
                                             (int)(50 - teams[t].bowlers[i].economy * 5);

            performances[perfCount].stats.bowl.wickets = teams[t].bowlers[i].wickets;
            performances[perfCount].stats.bowl.economy = teams[t].bowlers[i].economy;
            perfCount++;
        }
    }

    // Find best performance
    int bestIndex = 0;
    for (int i = 1; i < perfCount; i++)
    {
        if (performances[i].points > performances[bestIndex].points)
        {
            bestIndex = i;
        }
    }

    // Display Man of the Match
    puts("\n==========================================");
    puts("         MAN OF THE MATCH                ");
    puts("==========================================");
    printf("\n%s (%s from %s)\n",
           performances[bestIndex].name,
           performances[bestIndex].role,
           performances[bestIndex].team);

    if (strcmp(performances[bestIndex].role, "Batsman") == 0)
    {
        printf("Runs: %d\nStrike Rate: %.2f\n",
               performances[bestIndex].stats.bat.runs,
               performances[bestIndex].stats.bat.strike_rate);
    }
    else
    {
        printf("Wickets: %d\nEconomy: %.2f\n",
               performances[bestIndex].stats.bowl.wickets,
               performances[bestIndex].stats.bowl.economy);
    }
    puts("==========================================\n");
}

