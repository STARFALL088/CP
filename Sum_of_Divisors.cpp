#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int mod = 1000000007;
  int n;
  cin >> n;
  // int ck = 0;
  // for (int i = 0; i < n; i++)
  //   ck += n / (i + 1) * (i + 1);
  // cerr << ck;
  int cur = n;
  int l = n, r;
  int sum = 0;
  while (1) {
    int v = n / cur;
    r = n / v;

    int nxt = v + 1;
    cur = n / nxt;

    int z = 0;
    r = cur;
    z = v % mod * ((l + r + 1) % mod) % mod * ((l - r) % mod) % mod;
    z = z * ((mod + 1) / 2) % mod;
    sum += z;
    sum %= mod;
    l = r;

    if (cur < 1)
      break;
  }

  cout << sum % mod;
}
