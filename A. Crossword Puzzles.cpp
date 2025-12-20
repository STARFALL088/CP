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
    cout << "Case " << ii << ": ";
    int r, c;
    cin >> r >> c;
    vector<vector<char>> p(r + 2, vector<char>(c + 2, 'X'));
    string ans = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz"
                 "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz"
                 "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz"
                 "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
    error(ans.size());
    for (int i = 0; i < r; i++)
      for (int j = 0; j < c; j++)
        cin >> p[i + 1][j + 1];
    for (int i = 1; i <= r; i++) {
      string a;
      for (int j = 1; j <= c; j++) {
        if (p[i][j] == 'X') {
          if (a.size() >= 2) {
            if (a < ans)
              ans = a;
          }
          a.clear();
          continue;
        }
        a.push_back(p[i][j]);
        if (j == c) {
          if (a.size() >= 2) {
            if (a < ans)
              ans = a;
          }
          a.clear();
        }
      }
    }

    for (int i = 1; i <= c; i++) {
      string a;
      for (int j = 1; j <= r; j++) {
        if (p[j][i] == 'X') {
          if (a.size() >= 2) {
            if (a < ans)
              ans = a;
          }
          a.clear();
          continue;
        }
        a.push_back(p[j][i]);
        if (j == r) {
          if (a.size() >= 2) {
            if (a < ans)
              ans = a;
          }
          a.clear();
        }
      }
    }
    cout << ans << endl;
  }
}
