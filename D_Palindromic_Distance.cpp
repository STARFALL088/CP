#include <bits/stdc++.h>
#include <climits>
using namespace std;
#define int long long
string s;
int rec(vector<vector<int>> &dp, int i, int j) {
  if (i >= j)
    return 0;
  if (dp[i][j] != -1)
    return dp[i][j];
  int mn = INT_MAX;
  if (s[i] == s[j])
    return dp[i][j] = min(mn, rec(dp, i + 1, j - 1));
  else
    return dp[i][j] = min({mn, 1 + rec(dp, i + 1, j), 1 + rec(dp, i, j - 1),
                           1 + rec(dp, i + 1, j - 1)});
}
void action() {

  cin >> s;

  int n = s.size();
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
  int cnt = 0;

  cout << rec(dp, 0, n - 1) << endl;
}
signed main() {

  int t;
  cin >> t;
  for (int _ = 1; _ <= t; _++)
    action();
}