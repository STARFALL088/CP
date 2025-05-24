#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long lli;
const long long int MAXN = 1e6 + 1;

// *****************************************************
// ------------------- CODE STARTS HERE ----------------
// *****************************************************


int n, k ;
int f(int x)
{
    x-- ;
    return (x % n + 1) ;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t ;
    cin>>t ;
    while(t--) {

        cin>>n>>k ;
        if(n &1) cout<<f(k + (k - 1) / (n / 2))<<endl;
        else cout<<f(k)<<endl;
    }
    return 0 ;
}