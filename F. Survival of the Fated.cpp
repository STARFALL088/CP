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

  /// brute();
  int t = 1;
  cin >> t;
  for (int ii = 1; ii <= t; ii++) {

    int n;
    cin >> n;
    vector<int> p(n, 0);
    for (auto &i : p)
      cin >> i;
    sort(p.rbegin(), p.rend());
    vector<int> q(n / 2, 0);
    vector<int> z(n / 2, 0);
    z[0] = n - 1;
    for (int i = 1; i < n / 2; i++)
      z[i] = z[i - 1] - 2;
    for (int i = 0; i < n / 2; i++)
      q[i] = (p[i] - p[n - i - 1]) * z[i];
    int ans = 0;
    for (int i = 0; i < n / 2; i++)
      ans += (q[i]);
    cout << ans << endl;
  }
}
