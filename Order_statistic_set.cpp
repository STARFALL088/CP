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
  cin >> t;
  ordered_set<int> s;
  for (int ii = 1; ii <= t; ii++) {
    // debug(s);
    char c;
    int val;
    cin >> c >> val;
    if (c == 'I') {
      s.insert(val);
    } else if (c == 'D') {
      s.erase(val);
    } else if (c == 'K') {
      int ans = *s.find_by_order(--val);
      if (ans == 0)
        cout << "invalid" << endl;
      else
        cout << ans << endl;
    } else if (c == 'C') {
      cout << s.order_of_key(val) << endl;
    }
  }
}