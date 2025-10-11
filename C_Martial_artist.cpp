lli n, m;
vector<vector<char>> arr(1006, vector<char>(1006));
vector<vector<bool>> vis(1006, vector<bool>(1006));
bool isValid(lli x, lli y)
{
    return (x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && arr[x][y] != '#');
}

void dfs(lli x, lli y)
{
    vis[x][y] = true;

    for (lli i = 0; i < 4; i++)
    {
        lli nx = x + dx[i], ny = y + dy[i];
        if (isValid(nx, ny))
        {
            dfs(nx, ny);
        }
    }
}