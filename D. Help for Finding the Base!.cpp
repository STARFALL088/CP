#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
namespace std {
using namespace __gnu_pbds;
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
}; // namespace std

#ifndef ONLINE_JUDGE
#include "debug.hpp"
#else
#define debug(x)
#define error(...)
#endif
#define int long long
const int mod = 1e9 + 7; // 998244353;
#define all(x) (x).begin(), (x).end()
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  // cin>>t;
  for (int ii = 1; ii <= t; ii++) {
    int n;
    cin >> n;
    vector<vector<int>> c(n + 1, vector<int>(n + 1, 1));
    for (int i = 3; i <= n; i++) {
      for (int j = 2; j < i; j++) {
        c[i][j] = (c[i - 1][j - 1] % mod + c[i - 1][j] % mod) % mod;
      }
    }
    for (int i = 1; i <= n; i++)
      cout << char((--c[n][i] + 26) % 26 + 'a') << " ";
  }
}
