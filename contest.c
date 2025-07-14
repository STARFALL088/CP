#include<stdio.h>
#include<string.h>

int main()
{

    long long int t;
    scanf("%lld",&t);
    while(t--)
    {

        long long int n, x;
        //cin >> n >> x;
        scanf("%lld %lld",&n,&x);
        //printf("%lld %lld",n,x);
        long long ar[n];
        long long checker[2 * n + 10];
        for(long long int i=0;i<2*n+10;i++)checker[i]=0;
        for (long long  i =0 ; i < n; i++)
        {
            scanf("%lld",&ar[i]);
            if (ar[i] <= n)
            {
                checker[ar[i]]++;;
            }
        }
        for (long long int i =0; i <= n; i++)
        {
            if (checker[i] > 1 && i + x <= (n) + 1)
            {
                long long have = checker[i] - 1;
                checker[i] = 1;
                checker[i + x]+=have;
            }
        }
        for (long long int i = 0; i <= n; i++)
        {
            if (checker[i] == 0)
            {
                //cout << i << '\n';
                printf("%lld \n",i);
                break;
            }
        }


    }
}
