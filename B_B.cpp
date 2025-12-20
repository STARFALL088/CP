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
    int x, y;
    cin >> x >> y;
    if ((x == 1 or y == 1) or (x % 2 and y % 2)) {
      cout << -1 << endl;
    }

    else if (x % 2 == 0) {
      string s1, s2;
      for (int i = 0; i < x / 2; i++)
        s1.push_back('a');
      for (int i = 0; i < y; i++)
        s1.push_back('b');
      for (int i = 0; i < x / 2; i++)
        s1.push_back('a');
      for (auto i : s1)
        cout << i;
      cout << endl;

      s2.push_back('b');
      for (int i = 0; i < x / 2; i++)
        s2.push_back('a');
      for (int i = 0; i < y - 2; i++)
        s2.push_back('b');
      for (int i = 0; i < x / 2; i++)
        s2.push_back('a');
      s2.push_back('b');
      for (auto i : s2)
        cout << i;
      ;
      cout << endl;
    }

    else {
      string s1, s2;
      for (int i = 0; i < y / 2; i++)
        s1.push_back('b');
      for (int i = 0; i < x; i++)
        s1.push_back('a');
      for (int i = 0; i < y / 2; i++)
        s1.push_back('b');
      for (auto i : s1)
        cout << i;
      cout << endl;

      s2.push_back('a');
      for (int i = 0; i < y / 2; i++)
        s2.push_back('b');
      for (int i = 0; i < x - 2; i++)
        s2.push_back('a');
      for (int i = 0; i < y / 2; i++)
        s2.push_back('b');
      s2.push_back('a');
      for (auto i : s2)
        cout << i;
      cout << endl;
    }
  }
  // } else {
  //   string s1, s2;

  //   x /= 2;
  //   y /= 2;
  //   for (int i = 0; i < x; i++)
  //     s1.push_back('a');
  //   for (int i = 0; i < y; i++)
  //     s1.push_back('b');
  //   for (int i = 0; i < x + y; i++)
  //     cout << s1[i];
  //   for (int i = x + y - 1; i >= 0; i--)
  //     cout << s1[i];
  //   cout << endl;
  //   swap(x, y);
  //   s1 = s2;
  //   for (int i = 0; i < x; i++)
  //     s1.push_back('a');
  //   for (int i = 0; i < y; i++)
  //     s1.push_back('b');
  //   for (int i = 0; i < x + y; i++)
  //     cout << char(s1[i]^'a'^'b');
  //   for (int i = x + y - 1; i >= 0; i--)
  //     cout << char(s1[i]^'a'^'b');
  //   cout << endl;
  // }
}
