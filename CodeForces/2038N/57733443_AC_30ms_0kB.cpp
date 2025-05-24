#include<stdio.h>
#include<string.h>
char a[3];
int main()
{

    int t;
    scanf("%d",&t);
    ;
    while(t--)
    {
        //printf("%d",t);

        scanf("%s", a);
        if (a[0] == a[2])
        {
            a[1] = '=';
        }
        else if (a[0] > a[2])
        {
            a[1] = '>';
        }
        else
        {
            a[1] = '<';
        }
        printf("%c%c%c\n",a[0],a[1],a[2]);
    }
}
