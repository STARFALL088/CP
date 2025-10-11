#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
  int n, q;
  cin >> n >> q;
  vector<int> p(n);
  for (auto &i : p)
    cin >> i;
  int cnt = 0;
  for (int i = 0; i < n; i++)
    cnt += !!p[i];
  while (q--) {
    int a, b;
    cin >> a >> b;
    b--;
    if (a == 1) {
      if (p[b] == 1) {
        cnt--;
      }
      p[b]--;
    } else {
      if (p[b] == 0) {
        cnt++;
      }
      p[b]++;
    }

    cout << cnt << endl;
  }
}