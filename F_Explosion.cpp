#include <bits/stdc++.h>
using namespace std;
#define int long long
using ll = long long;

int MAXN = 100006;

void dfs(vector<vector<ll>> &adj,vector<bool> &vis,vector<int> &dp, ll v, ll p = -1) {
  vis[v] = 1;
  for (auto child : adj[v]) {
    if (vis[child] == 0) {
      dp[child] = dp[v] + 1;
      dfs(adj,vis,dp, child, v);
    }
  }
}
void action() {
  ll n, t, p;
  cin >> n >> t >> p;
  vector<vector<ll>> adj(n);
  vector<bool> vis(n, 0);
  vector<int> dp(n, 0);

  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dp[t - 1] = 0;
  dfs(adj,vis,dp, t - 1, -1);

  int down = n - 2;
  int up = dp[p - 1] - 1;
  if (up % 2 == 0) {
    cout << "1 1" << endl;
    return;
  }
  int g = gcd<ll>(up, down);
  if (g == 0)
    g = 1;
  cout << up / g << " " << down / g << endl;
  //   for (int i = 0; i < n; i++)
  //     cout << dp[i] << " ";
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  for (int ii = 1; ii <= t; ii++) {
    action();
  }
}