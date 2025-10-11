#include <bits/stdc++.h>
using namespace std;
#define int long long

void bfs(vector<vector<int>> &arr, vector<bool>&vis, vector<int>&dis, int n,
         int src) {
 
    queue<int> q;
    q.push(src);
    vis[src] = 1;
    dis[src]=0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto child : arr[v]) {
            if (vis[child] == 0) {
                vis[child] = 1;
                dis[child]=dis[v]+1;
                q.push(child);
            }
        }
    }
}
signed main() {
  int t;
  cin >> t;
  for (int _ = 0; _ < t; _++) {
    if(_) cout<<endl;
    int p, d;
    cin >> p >> d;
    vector<vector<int>> arr(p);
    vector<bool> vis(p, 0);
    vector<int> dis(p, 0);
    for (int i = 0; i < d; i++) {
        int a,b;
        cin>>a>>b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    bfs(arr,vis,dis,p,0);
    for(int i=1;i<p;i++)cout<<dis[i]<<endl;
   
  }
}