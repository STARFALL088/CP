#include <bits/stdc++.h>
using namespace std;
#define int long long
map<int, int> prime_factorize(int n) {
  map<int, int> factors;
  for (int i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      factors[i]++;
      n /= i;
    }
  }
  if (n > 1)
    factors[n]++;
  return factors;
}
signed main() {
  int n;
  cin >> n;
  int g = 1;
  map<int, int> z, ans;
  for (int ii = 0; ii < n; ii++) {
    int x;
    cin >> x;
    map<int, int> m = prime_factorize(x);
    for (auto [i, j] : m) {
      if (z.count(i)) {
        ans[i] = min(z[i], j);
        z[i] = max(z[i], j);
      } else
        z[i] = j;
    }
  
  }

  for (auto [i, j] : ans) {

    for (int k = 0; k < j; k++)
      g *= i;
  }
  cout << g;
}