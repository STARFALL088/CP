#include <bits/stdc++.h>
using namespace std;
long long MAXN = 1e8 + 2;

// *****************************************************
// ------------------- CODE STARTS HERE ----------------
// *****************************************************

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<bool> primes(MAXN, 1);
    primes[0] = primes[1] = 0;
    for (int i = 2; i * i <= MAXN; i++)
    {
        if (primes[i] == 1)
        {
            for (int j = i * i; j <= MAXN; j += i)
            {
                primes[j] = 0;
            }
        }
    }
    vector<long long> p;
    for (int i = 0; i <= MAXN; i++)
        if (primes[i])
            p.push_back(i);
    for (int i = 0; i < p.size(); i++)
    {
        if(i%100==0)cout<<p[i]<<endl;
    }
}