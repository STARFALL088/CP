#include <bits/stdc++.h>
using namespace std;
#define int long long
using lli = long long;
void action() {

  int n, q;
  cin >> n >> q;
  vector<int> p(n, 0);
  for (int i = 0; i < n; i++)
    cin >> p[i];
  for (int ii = 1; ii <= q; ii++) {
    int idx, val;
    cin >> idx >> val;
    // cerr << idx << endl;
    // idx++;
    p[idx] = val;
    // for (auto i : p)
    //   cerr << i << " ";
    // // cout << endl;
    if (idx and p[idx] == p[idx - 1])
      p.erase(p.begin() + (--idx));
    if (idx + 1 < p.size() and p[idx] == p[idx + 1])
      p.erase(p.begin() + idx);

    cout << p.size()<< endl;
  }
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  for (int ii = 1; ii <= t; ii++) {
    cout << "Case " << ii << ":" << endl;

    action();
  }
}