#include<stdio.h>
#include<string.h>

int main()
{

    long long int t;
    scanf("%lld",&t);

    while(t--)
    {

        long long int n;
        scanf("%lld",&n);
        long long int p[n+1];
        long long int sum1=0,sum2=0,cnt1=0,cnt2=0;
        for(long long int i=1; i<=n; i++)
        {
            scanf("%lld",&p[i]);

            if(i%2==0)
            {
                sum1+=p[i];
                cnt1++;
            }
            else
            {
                sum2+=p[i];
                cnt2++;
            }
        }
        if((sum1+sum2)%n==0&&sum1/cnt1==sum2/cnt2)
        {
            puts("YES");
        }
        else
        {
            puts("NO");

        }


    }
}
