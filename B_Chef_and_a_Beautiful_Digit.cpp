#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <string>
#include <vector>

#define ll long long int
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
#define endl '\n'
#define nl cout << endl;

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int MOD = 1e9 + 7;

void solve()
{
string n;cin>>n;char d;cin>>d;
vector<int>v[10];
for (int i=0;i<n.size();i++) {
v[n[i]-'0'].push_back(i);

}
int dig=0;
int lastidx=-1;
for (int i=1; i<10;i++) {
for (int x : v[i]) {
    // cout<<i<<" "<<x<<" "<<lastidx<<endl;
    if (lastidx<x&&i<d-'0') {
    cout<<i;
    lastidx=max(lastidx,x);
    }
    else {
    lastidx=max(lastidx,x);
    dig++;
    }

}

}
while (dig--) {
cout<<d;
}
cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    tc = 1;
    cin >> tc;

    while (tc--)
    {
        solve();
    }

    return 0;
}
