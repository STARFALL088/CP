#include <stdio.h>
#include <string.h>

int main()
{
    char s[1000], temps1[1000], temps2[1000], ans[30], *token1, *token2;

    scanf(" %[^\n]", s);

    strcpy(temps1, s);
    strcpy(temps2, s);

    token1 = strtok(temps1, " ");
    token2 = strtok(temps2, " ");

    int max = 0;
    for(int i = 1; token1; i++)
    {
        int count = 0;

        while(token2)
        {
            if(strcmp(token1, token2) == 0)
                count++;

            token2 = strtok(NULL, " ");
        }

        if(max < count)
        {
            max = count;
            strcpy(ans, token1);
        }

        strcpy(temps1, s);
        token1 = strtok(temps1, " ");

        for(int j = 0; j < i; j++)
            token1 = strtok(NULL, " ");

        strcpy(temps2, s);
        token2 = strtok(temps2, " ");
    }

    puts(ans);

    return 0;
}
