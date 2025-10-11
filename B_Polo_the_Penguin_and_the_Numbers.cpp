#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1000000007;
#define ln(n) (int)(log2l(n) / log2l(10))
int f(int x) {
  int last = ln(x) + 1;
  // cerr << last << " ";
  int l = 1, r = 9, z = 1;
  int sum = 0;
  for (int i = 1; i < last; i++) {
    sum += (i % mod * (l + r) % mod * (r - l + 1) % mod) % mod;
    // sum = sum * ((mod + 1) / 2) % mod;
    l *= 10;
    r *= 10;
    r += 9;
  }

  r = x;
  //   cerr << l << " " << r << " " << last << endl;

  sum += (last % mod * (l + r) % mod * (r - l + 1) % mod) % mod;
  //   sum = sum * ((mod + 1) / 2) % mod;
  sum = sum * ((mod + 1) / 2) % mod;

  return sum;
}
signed main() {
  int t;
  cin >> t;
  while (t--) {
    int l, r;
    cin >> l >> r;
    // cerr << f(r);
    cout << (f(r) % mod - f(l - 1) % mod + mod * mod) % mod << endl;
  }
}