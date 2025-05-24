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
    // CSES er ^_^

    int size;
    cin>>size;
    vector<int>p(size);
    input(p);
    lli mn=mod;
    for(int i=0; i<(1<<size)-1; i++) {
        lli sum=0;
        for(int j=0; j<size; j++) {
            ((i>>j)&1)?sum+=p[j]:sum-=p[j];
        }
        mn=min(mn,abs(sum));
    }
    cout<<mn<<endl;
}