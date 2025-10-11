#include <bits/stdc++.h>
#include <cstdint>
#include <cstdio>
using namespace std;

int main() {
//   freopen("crypto.in", "r", stdin);
//   freopen("crypto.out", "w", stdout);
  using lli = long long;
  using vll = vector<lli>;
  lli n, a, b;
  cin >> n >> a >> b;
  lli mx = INT64_MIN, x, y;
  lli z = (lli)log2(n + 1);
  lli X = (1 << (z)) - 1;
  for (int Y = 1; Y <= X; Y++) {
    int cur = ((a * X + b * Y) ^ (a * Y + b * X));
    if (cur > mx) {
      mx = cur;
      x = X;
      y = Y;
    }
  }
  cout << x << " " << y << endl;
  return 0;
}