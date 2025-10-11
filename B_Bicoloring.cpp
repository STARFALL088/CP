#include <bits/stdc++.h>
using namespace std;
#define int long long

int flag = 1;

set<int> s[2];

void dfs(vector<vector<int>> &arr, vector<bool> &vis, vector<int> &col, int v,
         int c = 0) {
  vis[v] = 1;
  col[v] = c;
  if (arr[v].size() >= 1)
    s[c].insert(v);
  for (auto child : arr[v]) {
    if (vis[child] == 0)
      dfs(arr, vis, col, child, c ^ 1);
    flag &= !(vis[child] && col[child] == c);
  }
}

signed main() {

  int p, d;
  while (cin >> p){
    if(p==0)return 0;
    cin >> d;
  vector<vector<int>> arr(p);
  vector<bool> vis(p, 0);
  vector<int> col(p, -1);
  for (int i = 0; i < d; i++) {
    int a, b;
    cin >> a >> b;
    arr[a].push_back(b);
    arr[b].push_back(a);
  }
  s[0].clear();
  s[1].clear();
  dfs(arr, vis, col, 0);
  cout << (flag ? "BICOLORABLE." : "NOT BICOLORABLE.") << endl;
  flag = 1;
}
}

bip