
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
  for (int ii = 1; ii <= t; ii++) {
    string s;
    cin >> s;
    stack<char> st;
    for (auto i : s) {
      if (st.empty() == 0 and st.top() == i)
        st.pop();
      else
        st.push(i);
    }
    if (st.empty() == 0)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
}
