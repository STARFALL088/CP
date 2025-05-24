#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long lli;
typedef long double lld;
const lli MAXN = 1e6 + 1;
const lli MOD = 1e9 + 7;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sort(x) sort(all(x))
#define rev(x) reverse(all(x))
#define rounded(a, b) ((a + (b / 2)) / b)
#define ceil(a, b) (a / b + (a % b != 0))
#define pb push_back
#define F first
#define S second
#define sq(x) ((x) * (x))
#define setpre(n) fixed << setprecision(n)
#define tc    \
    int t;    \
    cin >> t; \
    while (t--)
#define tc0    \
    int t = 1; \
    while (t--)
#define nl cout << "\n";
#define input(x)      \
    for (auto &i : x) \
    cin >> i

string ny[2] = {"NO", "YES"};

// ********************** FUNCTIONS*******************************

// PRINT 2D ARRAY
void print2DArray(const vector<vector<lli>> &a)
{
    lli n = a.size();
    lli m = a[0].size();
    for (lli i = 0; i < n; i++)
    {
        for (lli j = 0; j < m; j++)
        {
            cout << a[i][j] << " \n"[j == m - 1];
        }
    }
}

// POWER
lli exp(lli a, lli b)
{
    lli prod = 1;
    while (b != 0)
    {
        if (b % 2 == 0)
        {
            b /= 2;
            a = sq(a) % mod;
        }
        else
        {
            b--;
            prod *= a % mod;
            prod %= mod;
        }
    }
    return prod % mod;
}

// BIGMOD
// MOD INVERSE
lli bigmod(lli a, lli b)
{
    lli m = MOD;
    a %= m;
    lli res = 1;
    while (b > 0)
    {
        if (b & 1LL)
            res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1LL;
    }
    return res;
}


//DFS
void dfs(int v, vector<vector<int>> &arr, vector<bool> &vis)
{
    vis[v] = 1;
    cout << v << "->";
    for (int child : arr[v])
        if (vis[child] == 0)
            dfs(child, arr, vis);
}


// *****************************************************
// ------------------- CODE STARTS HERE ----------------
// *****************************************************
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    tc0
    {
        //prefix sum
        for (lli i = 1; i < n; i++)
        {
            p[i] += p[i - 1];
        }
    }
}
