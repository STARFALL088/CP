#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long lli;
typedef long double lld;
const long long int MAXN = 10e6+ 1;
const long long mod = 1e9 + 7;
#define pb push_back
#define F first
#define S second
#define sq(x) ((x) * (x))
#define setpre(n) fixed << setprecision(n)
#define tc int t;cin>>t;while(t--)
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
    vector<int>v= {1,2,4,8,16,32,64};
    auto it=upper_bound(v.begin(),v.end(),n) - v.begin();
    cout<<v[it-1];
}