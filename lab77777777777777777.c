#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>

int main()
{

    char s[1000];
    gets(s);

    const char *del = " ";
    char *arr[1000];
    char *token = strtok(s, del);

    int i = 0;
    int j = 0;
    while (token != '\0')
    {
        arr[++i] = token;
        // for(int _=0;_<i;_++){
        //     if(token==arr[_])
        // }
        token = strtok(NULL, del);

        j++;
    }

    for (int i = 1; i <= j; i++)
    {
        int cnt = 1;
        for (int k = i + 1; k <= j; k++)
        {
            if (strcmp(arr[i], arr[k]) == 0)
            {
                cnt++;
                arr[k] = "";
            }
        }
        if (arr[i] != "")
            printf("%s %d \n", arr[i], cnt);
    }
}