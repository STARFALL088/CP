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
int p[26][26];

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int MAXN = 10000;
  vector<int> pr;
  vector<bool> primes(MAXN + 1, 1);
  primes[0] = primes[1] = 0;
  for (int i = 2; i * i <= MAXN; i++) {
    if (primes[i] == 1) {
      for (int j = i * i; j <= MAXN; j += i) {
        primes[j] = 0;
      }
    }
  }
  for (int i = 2; i <= MAXN; i++)
    if (primes[i])
      pr.push_back(i);
  int t = 1;
  int type = 0;
  //    cin>>t;
  for (int ii = 1; ii <= t; ii++) {
    int n = ii;
    cin >> n;
    if (n == 1) {
      return cout << 1 << endl, 0;
    }
    int tot = n * n;
    int a, b;
    for (int i : pr) {
      if (i > tot)
        break;
      if (primes[i] and primes[tot - i]) {
        a = tot - i;
        b = i;
        break;
      }
      if (primes[i] and primes[tot - i - 1]) {
        a = tot - i - 1;
        b = i;
        type = 1;
        break;
      }
    }
    error(a, b);
    if (a == b) {
      a = tot - 1;
      b = 1;
    }
    error(a, b);

    int cnt = b;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (gcd<int>(i + 1, b) == 1 and gcd<int>(j + 1, b) == 1 and cnt > 0)
          p[i][j] = b, cnt--;
        else
          p[i][j] = a;
        if (type == 1)
          p[n - 1][n - 1] = 1;
        cout << p[i][j] << (j != n - 1 ? " " : "\n");
      }
    }
  }
}
