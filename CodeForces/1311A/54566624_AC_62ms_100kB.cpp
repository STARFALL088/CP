#pragma GCC optimize("Ofast")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long lli;
typedef long double lld;
const lli mod = 1e9 + 7;
const lli MAXN = 1e6;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define rev(x) reverse(all(x))
#define srt(x) sort(all(x))
#define pb push_back
#define F first
#define S second
#define sq(x) ((x) * (x))
#define setpre(n) fixed << setprecision(n)
#define UNIQUE(a) (a).erase(unique(all(a)),(a).end())
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
        int a,b;
        cin>>a>>b;
        //decrement
        if(b==a)cout << "0" << endl;
        else if(a>b) {
            //odd->even ==2
            // even->odd===2
            if((a%2==0&&b%2!=0)||(a%2!=0&&b%2==0)) {
                cout << "2" << endl;
            }

            //odd->odd=1
            //even->even=1
            else if((a%2==0&&b%2==0)||(a%2!=0&&b%2!=0)) {
                cout << "1" << endl;
            }
        }

        else if(a<b) {
            //even->odd=1
            //odd->even=1
            if((a%2==0&&b%2!=0)||(a%2!=0&&b%2==0)) {
                cout << "1" << endl;
            }
            //even->even=2
            //odd->odd=2
            else if((a%2==0&&b%2==0)||(a%2!=0&&b%2!=0)) {
                cout << "2" << endl;
            }
        }
    }
}