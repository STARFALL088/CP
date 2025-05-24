#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long lli;
typedef long double lld;
const lli MAXN = 1e6 + 1;
const lli mod = 1e9 + 7;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define rev(x) reverse(all(x))
#define sort(x) sort(all(x))
#define rsort(x) sort(rall(x))
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
#define print(x)      \
    for (auto &i : x) \
    cout << i << " "
inline int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
string ny[2] = {"NO", "YES"};

// *****************************************************
// ------------------- CODE STARTS HERE ----------------
// *****************************************************

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    lli n, m, k;
    cin >> n >> m >> k;

    vector<lli> p(n + 1, 0);
    vector<lli> a(n);
    for (lli i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<vector<lli>> operations(m, vector<lli>(3));
    for (lli i = 0; i < m; i++)
    {
        cin >> operations[i][0] >> operations[i][1] >> operations[i][2];
        operations[i][0]--;
        operations[i][1]--;
    }
    vector<lli> op(m + 1);

    while (k--)
    {
        lli x, y;
        cin >> x >> y;
        x--;
        y--;
        op[x]++;
        op[y+1]--;
    }
    // prefix sum
    for (lli i = 1; i < m; i++)
    {
        op[i] += op[i - 1];
    }

    for (lli i = 0; i < m; i++)
    {
        lli l = operations[i][0];
        lli r = operations[i][1];
        lli d = operations[i][2];

        p[l] += d * op[i];
        if (r + 1 < n)
            p[r + 1] -= d * op[i];
    }

    // prefix sum
    for (lli i = 1; i < n; i++)
    {
        p[i] += p[i - 1];
    }

    // Update
    for (lli i = 0; i < n; i++)
    {
        a[i] += p[i];
        cout << a[i] << " ";
    }
    nl;
}