#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<bool> primes(1000010, 1);

void action() {
  int n, m;
  cin >> n >> m;
  vector<int> dp(n + 1, 0);
  for (int i = 0; i < m; i++) {
    int x, y, v;
    cin >> x >> y >> v;
    int X = dp[x];
    int Y = dp[y];
    dp[y] = X + v;
    dp[x] = Y + v;
  }
  cout << *max_element(dp.begin(), dp.end()) << endl;
}
signed main() {

  int t;
  cin >> t;
  for (int _ = 1; _ <= t; _++)
    action();
}