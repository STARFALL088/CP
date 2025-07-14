#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<long long>p(1000003,0);
    for(int i=1;i<1000002;i++){
        lli n=i;
        p[i]=p[i-1]+n*(n+1)/2+n-1;
        lli x;
        if(i%2){
            x=
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        lli n;
        cin>>n;
        cout<<p[n]<<endl;
    }
}