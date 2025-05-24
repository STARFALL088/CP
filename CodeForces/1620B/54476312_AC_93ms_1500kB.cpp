#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long lli;
typedef long double lld;
const lli mod = 1e9 + 7;
const lli MAXN = 24;
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
#define pi acos(-1.0) / 180.0
#define vec2d(name, n, m, val) vector<vector<int>> name((n), vector<int>((m), (val)))
#define tc    \
    int t;    \
    cin >> t; \
    for (int ii = 1; ii <= t; ++ii)
#define tc0    \
    int t = 1; \
    for (int ii = 1; ii <= t; ++ii)
#define nl cout << "\n";
#define case(ii) cout << "Case " << ii << ": ";
#define input(x) for (auto &i : x) cin >> i
#define print(x) for (auto &i : x) cout << i << " ";

constexpr int dx[] = {0, 0, 1, -1};
constexpr int dy[] = {1, -1, 0, 0};

inline int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

#define lcm(a, b) ((a) * (b)) / gcd(a, b)
const string ny[] = {"NO", "YES"};

// *****************************************************
// ------------------- CODE STARTS HERE ----------------
// *****************************************************


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    tc {
        int w, h;
        cin>>w>>h;
        lli k1;
        cin>>k1;
        vll ar1(k1);
        for(int i=0; i<k1; i++) cin>>ar1[i];
        k1=h*(ar1[k1-1]-ar1[0]);

        lli k2;
        cin>>k2;
        vll ar2(k2);
        for(int i=0; i<k2; i++) cin>>ar2[i];
        k2=h*(ar2[k2-1]-ar2[0]);

        lli k3;
        cin>>k3;
        vll ar3(k3);
        for(int i=0; i<k3; i++) cin>>ar3[i];
        k3=w*(ar3[k3-1]-ar3[0]);

        lli k4;
        cin>>k4;
        vll ar4(k4);
        for(int i=0; i<k4; i++) cin>>ar4[i];
        k4=w*(ar4[k4-1]-ar4[0]);

        cout<<max(max(k1,k2),max(k3,k4))<<endl;
    }

}