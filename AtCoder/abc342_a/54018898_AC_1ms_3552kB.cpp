#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long lli;
typedef long double lld;
const lli MAXN = 1e6 + 1;
const lli mod = 1e9 + 7;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define rev(x) reverse(all(x))
#define sort(x) sort(all(x))
#define rsort(x) sort(rall(x))
#define pb push_back
#define F first
#define S second
#define sq(x) ((x) * (x))
#define setpre(n) fixed << setprecision(n)
#define tc    \
    int t;    \
    cin >> t; \
    while (t--)
#define tc0    \
    int t=1;   \
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
    string s;
    cin>>s;
    string p=s;
    sort(p);
    char target;
    if(p[0]!=p[1]) target=p[0];
    else target=p[p.size()-1];
    for(int i=0; i<s.size(); i++) {
        if(s[i]==target) {
            cout << i+1 << endl;
            break;
        }
    }
}