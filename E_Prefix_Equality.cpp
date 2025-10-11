#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
  int n;
  cin >> n;
  map<int, int> m1, m2;

  vector<int> p(n), q(n), _p(n), _q(n);
  for (auto &i : p)
    cin >> i;
  for (auto &i : q)
    cin >> i;
  for (int i = n-1; i >=0; i--)
    m1[p[i]] = i, m2[q[i]] = i;
  for (int i = 0; i < n; i++) {

  }
  int t;
  cin >> t;
  while (t--) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    if (_p[x] == _q[y])
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
}