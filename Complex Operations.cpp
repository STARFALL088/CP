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
    int n, q;
    cin >> n >> q;
    vector<int> p(n);
    for (auto &i : p) {
      cin >> i;
    }
    sort(all(p));
    debug(p);
    int sum = 0;
    while (q--) {
      int type;
      cin >> type;
      if (type == 1) {
        int val;
        cin >> val;
        sum += val;
      } else {
        int l, r, k;
        cin >> l >> r >> k;
        l += sum;
        r += sum;
        auto pos = lower_bound(all(p), l) - p.begin();
        if (pos + k - 1 >= n or p[pos + k - 1] > r)
          cout << -1 << endl;
        else
          cout << p[pos + k - 1] - sum << endl;
      }
    }
  }
}
