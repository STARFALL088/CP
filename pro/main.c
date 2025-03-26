#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "login.h"
#include "man_of_the_match.h"
#include "winner.h"
#include "welcome.h"
#include "begin.h"
#include "function.h"
#include "option.h"
#include "signup.h"
#include "manage_team.h"
#include "simulate_match.h"
#include "view_next_ball.h"
#include "view_current_status.h"
#include "save_match_to_file.h"
#include "view.h"
#include "save_user_to_file.h"
#include "load_from_file.h"
#include "load_team.h"
#include "load_user.h"
#include "initialize_team.h"
#include "is_strong.h"
#include "is_user_name_taken.h"


#define MAX_PLAYERS 11
#define MAX_TEAMS 2
#define MAX_OVERS 3
#define USERNAME_LENGTH 20
#define PASSWORD_LENGTH 20
#define MAX_USERS 100

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"


int main()
{
    srand(time(0)); // Seed for random number generation
    welcome();

    userCount = loadUsersFromFile();
    initializeTeams(teams);
    begin();
    if(end_of_match==1)return 0;

    return 0;
}









