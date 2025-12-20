vector<vector<int>> arr(MAXN);
vector<bool> vis(MAXN);
void dfs(int v) {
    vis[v] = 1;
    for (auto child : arr[v]) {
        if (vis[child] == 0) dfs(child);
    }
}