#include"function.h"


void saveUsersToFile(int userCount)
{
    FILE *file = fopen("users.txt", "w");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    for (int i = 0; i < userCount; i++)
    {
        fprintf(file, "%s %s %d\n", users[i].username, users[i].password, users[i].teamIndex);
    }

    fclose(file);
}