#include <bits/stdc++.h>
using namespace std;
#define int long long
using lli = long long;

void topological_sort(lli node, vector<vector<lli>> &adj, vector<lli> &visited, stack<lli> &st) {
    visited[node] = 1;
    for (auto &neighbor : adj[node]) {
        if (!visited[neighbor]) {
            topological_sort(neighbor, adj, visited, st);
        }
    }
    st.push(node);
}
vector<lli> get_toposort(lli n, vector<vector<lli>> &adj) {
    vector<lli> visited(n, 0);
    stack<lli> st;
    for (lli i = 0; i < n; i++) {
        if (!visited[i]) {
            topological_sort(i, adj, visited, st);
        }
    }
    vector<lli> order;
    while (!st.empty()) {
        order.push_back(st.top());
        st.pop();
    }
    return order;
}

void action() {
    int n,m;
    cin>>n>>m;

}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  //   cin >> t;
  for (int ii = 1; ii <= t; ii++) {
    action();
  }
}