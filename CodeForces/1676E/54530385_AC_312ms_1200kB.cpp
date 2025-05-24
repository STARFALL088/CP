#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long lli;
typedef long double lld;
const lli mod = 1e9 + 7;
const lli MAXN = 10e6;
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
#define arrsum(arr) std::accumulate(arr.begin(), arr.end(), 0LL)


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
    tc{
        lli size,q;
        cin>>size>>q;
        vector<lli>p(size);
        input(p);
        srt(p);
        rev(p);
        for(int i=1; i<size; i++)p[i]+=p[i-1];
        //print(p);nl
        while(q--) {
            lli n;
            cin>>n;
            if(n>p[size-1]) {
               cout << "-1" << endl;
                continue;
            }
            auto it=lower_bound(all(p),n)-p.begin()+1LL;
            cout<<it<<endl;
        }
    }
}