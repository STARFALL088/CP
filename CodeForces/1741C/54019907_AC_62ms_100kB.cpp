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
    tc{
        int n;
        cin>>n;
        vector<int>v(n);
        input(v);
        int res=n;
        for(int i=0; i<n; i++) {
            lli cur=0;
            int mx=i+1;
            bool flag=1;
            for(int j=0; j<=i; j++)cur+=v[j];
            int cnt=0;
            lli c=0;
            for(int j=i+1; j<n; j++) {
                cnt++;
                c+=v[j];
                if(c==cur) {
                    mx=max(mx,cnt);
                    cnt=0;
                    c=0;
                }
            }
            if(c==0)res=min(res,mx);
        }
        cout<<res;
        nl
    }
}
