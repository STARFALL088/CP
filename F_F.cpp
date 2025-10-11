#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using lli = long long;
using vll = vector<lli>;
int main() {
  // freopen("crypto.in", "r", stdin);
  // freopen("crypto.out", "w", stdout);
  lli n;
  cin >> n;
  lli sum = 0;
  vector<lli> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  sort(p.begin(), p.end());
  for (int i = 30; i >= 0; i--) {
    lli cnt = 0, z = -1;
    for (int j = 0; j < n; j++) {
      cnt += !!((1LL << i) & p[j]);
      if (1LL << (j + 1) > p[j])
        z = i;
    }
    // cerr<<cnt<<endl;
    if (cnt == 0)
      continue;
    if (z == -1)
      continue;
    lli baki = n - cnt;

    if (baki < cnt) {
      lli tmp = p[z];
      for (int x = 0; x < n; x++) {
        p[x] ^= tmp;
      }
    }
  }
  for (int i = 0; i < n; i++)
    cout << p[i] << " ";
  cout << sum;
}