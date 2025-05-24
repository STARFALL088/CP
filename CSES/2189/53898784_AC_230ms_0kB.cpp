#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long lli;
typedef long double lld;
const lli MAXN = 1e4 + 1;
const lli mod = 1e9 + 7;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
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
#define input(x) for(auto &i:x) cin>>i
inline int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
string ny[2] = {"NO", "YES"};

// *****************************************************
// ------------------- CODE STARTS HERE ----------------
// *****************************************************

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    tc{
        lli x1,y1,x2,y2,x3,y3;
        cin>>x1>>y1>>x2>>y2>>x3>>y3;
        lli area=x1*y2-x2*y1+x2*y3-x3*y2+x3*y1-y3*x1;
        if(area==0) cout << "TOUCH" << endl;
        else if(area>0) cout << "LEFT" << endl;
        else cout << "RIGHT" << endl;
    }
}