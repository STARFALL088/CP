#include "function.h"


int loadUsersFromFile()
{
    FILE *file = fopen("users.txt", "r");
    if (file == NULL)
    {
        return 0; // No users file exists yet
    }

    int userCount = 0;
    while (fscanf(file, "%s %s %d", users[userCount].username, users[userCount].password, &users[userCount].teamIndex) != EOF)
    {
        userCount++;
    }

    fclose(file);
    return userCount;
}
