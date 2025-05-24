#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long lli;
typedef long double lld;
const lli MAXN = 1e5 + 1;
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
#define print(x) for(auto &i:x) cout<<i<<" "
inline int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
string ny[2] = {"NO", "YES"};

// *****************************************************
// ------------------- CODE STARTS HERE ----------------
// *****************************************************
void dfs(int v,vector<vector<int>>&arr,vector<bool>&vis) {
    vis[v]=1;
    for(auto child:arr[v]) {
        if(vis[child]==0)dfs(child,arr,vis);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli ans=0;
    int n,k;
    cin>>n>>k;
    vector<bool>vis(n+1,0);
    vector<vector<int>>arr(n+1);
    while(k--) {
        int a,b;
        cin>>a>>b;
        arr[a].pb(b);
        arr[b].pb(a);
    }
    vector<int>p;
    for(int i=1; i<=n; i++) {
        if(vis[i]==0) {
            dfs(i,arr,vis);
            p.pb(i);
        }
    }
    cout<<p.size()-1<<endl;
    for(int i=1; i<p.size(); i++) {
        cout<<p[0]<<" "<<p[i]<<endl;
    }
}