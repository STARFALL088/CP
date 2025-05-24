#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long lli;
typedef long double lld;
const lli mod = 1e9 + 7;
const lli MAXN = 1e6 + 7;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define rev(x) reverse(all(x))
#define srt(x) sort(all(x))
#define pb push_back
#define F first
#define S second
#define sq(x) ((x) * (x))
#define setpre(n) fixed << setprecision(n)
#define vi vector<int>
#define vc vector<char>
#define vs vector<string>
#define vll vector<lli>
#define vb vector<bool>
#define pi acos(-1.0)
#define vec2d(name,n,m,val) vector<vector<int>>(name)((n),vector<int>((m),(val)))
#define tc    \
    int t;    \
    cin >> t; \
    for (int i = 1; i <= t; ++i)
#define tc0   \
    int t = 1; \
    for (int i = 1; i <= t; ++i)
#define nl cout << "\n";
#define case(i) cout << "Case #" << i << ": ";
#define input(x) for(auto &i:x) cin>>i
#define print(x) for(auto &i:x) cout<<i<<" ";

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
inline int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
#define lcm(a,b)    (a*b)/gcd(a,b)
string ny[2] = {"NO", "YES"};

// *****************************************************
// ------------------- CODE STARTS HERE ----------------
// *****************************************************

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vi p(n);
    input(p);
    srt(p);
    set<int>s;
    for(int i=0; i<n; i++) {
        s.insert(p[i]);
    }
    cout<<s.size()<<endl;
}