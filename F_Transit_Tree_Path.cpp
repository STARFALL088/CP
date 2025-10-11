#include <bits/stdc++.h>
using namespace std;
using lli = long long;
lli MAXN = 1e6 + 669;

void bfs(vector<vector<pair<lli,lli>>>&arr, vector<bool>&vis,vector<lli>&dis, lli src) {
  queue<lli> q;
  q.push(src);
  vis[src] = 1;
  dis[src]=0;
  while (!q.empty()) {
    lli v = q.front();
    q.pop();
    for (auto [child,ds] : arr[v]) {
      if (vis[child] == 0) {
        vis[child] = 1;
        dis[child]=dis[v]+ds;
        q.push(child);
      }
    }
  }
}
void action() {
  lli n;
  cin >> n;
  vector<vector<pair<lli, lli>>> p(n + 1);
  vector<bool>vis(n+1,0);
  for (int i = 0; i < n - 1; i++) {
    lli a, b, c;
    cin >> a >> b >> c;
    p[a].push_back({b, c});
    p[b].push_back({a, c});
  }
  lli q, k;
  cin >> q >> k;
  vector<lli>dis(n+1,0);
  bfs(p,vis,dis,k);
  for (int i = 0; i < q; i++) {
    lli a, b;
    cin >> a >> b;
    cout << dis[a] + dis[b] << endl;
  }
}
int main(int argc, char *argv[]) {
  int t = 1;
  // cin>>t;
  action();
  // cout << (action() ? "Yes" : "No");
  return 0;
}