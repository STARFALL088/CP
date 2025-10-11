#include <bits/stdc++.h>
#include <vector>
using namespace std;
using lli = long long;
using vll = vector<lli>;
lli n;
vector<vector<int>> adj;
vector<bool> vis;
vector<int> par;
map<lli, lli> mp;
lli cycle_start, cycle_end;
bool dfs(int v, int p) {
  vis[v] = 1;
  for (int u : adj[v]) {
    if (u == p)
      continue;
    if (vis[u]) {
      cycle_end = v;
      cycle_start = u;
      return true;
    }
    par[u] = v;
    if (dfs(u, v))
      return 1;
  }
  return 0;
}

class DSU {
  vll rank, parent;

public:
  DSU(lli n) {
    rank.resize(n + 1, 0);
    parent.resize(n + 1);
    for (lli i = 0; i <= n; ++i) {
      parent[i] = i;
    }
  }

  lli find(lli node) {
    if (node == parent[node]) {
      return node;
    }
    return parent[node] = find(parent[node]); // Path compression
  }

  void unionSets(lli u, lli v) {
    lli rootU = find(u);
    lli rootV = find(v);

    if (rootU == rootV) {
      return; // Both elements are already in the same set
    }

    // Union by rank
    if (rank[rootU] < rank[rootV]) {
      parent[rootU] = rootV;
    } else if (rank[rootV] < rank[rootU]) {
      parent[rootV] = rootU;
    } else {
      parent[rootV] = rootU;
      rank[rootU]++;
    }
  }
};
void find_cyc() {
  vis.assign(n + 1, false);
  par.assign(n + 1, -1);
  cycle_start = -1;
  for (int v = 1; v <= n; v++) {
    if (!vis[v] and dfs(v, -1))
      break;
  }
  mp[cycle_start]++;
  for (int v = cycle_end; v != cycle_start; v = par[v])
    mp[v]++;
  mp[cycle_start]++;
}
int main() {

  cin >> n;
  vector<pair<lli, lli>> z(n);
  adj.resize(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> z[i].first >> z[i].second;
    lli a = z[i].first;
    lli b = z[i].second;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  find_cyc();
//   for (auto [i, j] : mp) {
//     cout << i << " ";
//   }
  DSU p(n);
  for (auto [i, j] : z) {
    if (mp.count(i) and mp.count(j))
      continue;
    p.unionSets(i, j);
  }
  lli q;
  cin >> q;
  while (q--) {
    lli x, y;
    cin >> x >> y;
    if (p.find(x) == p.find(y))
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
}