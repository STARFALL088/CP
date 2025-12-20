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
bool color(int r, int c) { return r % 2 == c % 2; }
bool action() {

  int n, m, r1, c1, r2, c2;
  cin >> n >> m >> r1 >> c1 >> r2 >> c2;

  int a = max(r1, r2), b = min(r1, r2);
  int c = max(c1, c2), d = min(c1, c2);
  bool edge = ((n == 1 and m % 2 == 0 and (d - 1) % 2 == 0 and
                (c - 1 - d) % 2 == 0 and (m - c) % 2 == 0) or
               (m == 1 and n % 2 == 0 and (b - 1) % 2 == 0 and
                (a - 1 - b) % 2 == 0 and (n - a) % 2 == 0));
  if (edge)
    return 1;
  if ((n * m) % 2)
    return 0;
  if (n > 1 and m > 1 and color(r1, c1) != color(r2, c2))
    return 1;
  return 0;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  for (int ii = 1; ii <= t; ii++) {
    cout << (action() ? "YES" : "NO") << endl;
  }
}
