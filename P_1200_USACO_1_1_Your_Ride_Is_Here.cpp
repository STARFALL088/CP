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
  string a, b;
  cin >> a >> b;
  int cnt1 = 1, cnt2 = 1;
  for (auto i : a)
    cnt1 *= (i - 'A');
  for (auto i : b)
    cnt2 *= (i - 'A');
  if (cnt1 % 47 != cnt2 % 34) {
    cout << "GO";
  } else {
    cout << "STAY";
  }
}