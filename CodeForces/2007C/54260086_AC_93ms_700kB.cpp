#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long lli;
typedef long double lld;
const lli MAXN = 1e4+ 1;
const lli mod = 1e9 + 7;
#define pb push_back
#define F first
#define S second
#define sq(x) ((x) * (x))
#define setpre(n) fixed << setprecision(n)
#define tc    \
    int t;    \
    cin >> t; \
    while (t--)
#define nl cout << "\n";
string ny[2] = {"NO", "YES"};

// *****************************************************
// ------------------- CODE STARTS HERE ----------------
// *****************************************************
inline int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);    
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    tc{
        lli n,a,b;
        cin>>n>>a>>b;
        lli c=gcd(a,b);
        vector<lli> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
            p[i]%=c;
        }
        sort(p.begin(),p.end());
        int mn=p[n-1]-p[0];
        for (int i = 1; i < n; i++) {
        lli gap=p[i]-p[i-1];
            mn=fmin(mn,c-gap);
        }
        cout <<(lli) mn << endl;
    }
}