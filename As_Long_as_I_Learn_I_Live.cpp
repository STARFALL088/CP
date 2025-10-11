#include <bits/stdc++.h>
#include <queue>
using namespace std;
#define int long long

void dfs(vector<priority_queue<pair<int, int>>> arr, vector<bool> vis, int v,int sum) {
  vis[v] = 1;
  int cur=arr[v].top().second;
  sum+=arr[v].top().first;
  arr[v].pop();
}
signed main() {

  int p, d;
  cin >> p >> d;
  vector<int> x(p);
  for (auto &i : x)
    cin >> i;
  vector<priority_queue<pair<int, int>>> arr(p);
  vector<bool> vis(p, 0);
  vector<int> col(p, -1);
  for (int i = 0; i < d; i++) {
    int a, b;
    cin >> a >> b;
    arr[a].push({x[b], a});
    arr[b].push({x[a], b});
  }
  dfs(arr, vis, 0,0);
}
