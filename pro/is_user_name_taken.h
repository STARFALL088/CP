#include "function.h"

int isUsernameTaken(const char *username)
{
    int userCount = loadUsersFromFile();
    for (int i = 0; i < userCount; i++)
    {
        if (strcmp(users[i].username, username) == 0)
        {
            return 1;
        }
    }
    return 0;
}
