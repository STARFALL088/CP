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
    lli size, t;
    cin >> size >> t;
    vector<lli> p(size + 1);
    for (lli i = 1; i <= size; i++)
        cin >> p[i];
    p[0] = 0;
    for (lli i = 1; i <= size; i++)
    {
        p[i] += p[i - 1];
    }
    while (t--)
    {
       lli a, b;
        cin >> a >> b;
        a--;
        cout << p[b] - p[a] << endl;
    }
}