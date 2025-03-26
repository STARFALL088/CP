
void winner()
{
    Team winner;
    if (teams[0].totalRuns > teams[1].totalRuns)
        winner = teams[0];
    else
        winner = teams[1];
    puts(BLUE "===========================================" RESET);
    puts(BLUE "             CRICKET MATCH RESULT         " RESET);
    puts(BLUE "===========================================" RESET);
    puts(BLUE "Teams: " RESET);
    puts(" ");
    printf(BLUE "        %s  vs  %s\n" RESET, teams[0].name, teams[1].name);
    puts(BLUE "-------------------------------------------" RESET);
    puts(BLUE "             WINNER ANNOUNCEMENT        " RESET);
    puts(" ");
    printf(BLUE "               %s \n" RESET, winner.name);
    puts(" ");
    puts(BLUE "===========================================" RESET);
    puts(BLUE "  Congratulations to the winning team!     " RESET);
    puts(BLUE "===========================================" RESET);
    return;
}