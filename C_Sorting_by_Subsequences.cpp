#include <bits/stdc++.h>
using namespace std;
#define int long long

void dfs(int v, vector<vector<int>> arr,vector<bool> vis,int n) {
  vis[v] = 1;
  for (auto child : arr[v]) {
    if (vis[child] == 0)
      dfs(child,arr,bool,n);
  }
}
signed main() {
  int n;
  cin >> n;
}
}