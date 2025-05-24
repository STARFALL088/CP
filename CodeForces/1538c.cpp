#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include <bits/stdc++.h>
using namespace std;

// Type definitions
typedef long long ll;
typedef long long lli;
typedef long double lld;
typedef pair<int, int> pii;
typedef pair<lli, lli> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<lli> vll;
typedef vector<vll> vvl;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<vc> vvc;

// Constants
const lli mod = 1e9 + 7; // 998244353;
const lli MAXN = 1e6;
const double eps = 1e-10;
const lli LINF = 1001002003004005006ll;
const int INF = 1001001001;
const int MX = 200005;
constexpr int dx[] = {0, 0, 1, -1};
constexpr int dy[] = {1, -1, 0, 0};
const string ny[] = {"NO", "YES"};
const string nys[] = {"No", "Yes"};
// Macros
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rev(x) reverse(all(x))
#define srt(x) sort(all(x))
#define max (lli) std::max
#define maxx (lli) fmax
#define minn (lli) fmin
#define pb push_back
#define F first
#define S second
#define pi acos(-1.0)
#define sq(x) ((x) * (x))
#define issq(x) (((lli)(sqrt((x)))) * ((lli)(sqrt((x)))) == (x))
#define lg(r, n) (int)(log2(n) / log2(r))
#define setpre(n) fixed << setprecision(n)
#define UNIQUE(a) (a).erase(unique(all(a)), (a).end())
#define take(p, n, T) \
    vector<T> p(n);   \
    for (auto &i : p) \
        cin >> i;

#define input(x)      \
    for (auto &i : x) \
    cin >> i
#define print(x)          \
    for (auto &i : x)     \
        cout << i << " "; \
    cout << "\n"
#define arrsum(arr) std::accumulate(arr.begin(), arr.end(), 0LL)

// Loop macros
#define loop(i, n) for (int i = 0; i < (n); ++i)
#define rloop(i, n) for (int i = (n) - 1; i >= 0; --i)
#define sloop(i, s, t) for (int i = s; i < t; ++i)

// Utility macros
#define maxs(x, y) (x = max(x, y))
#define mins(x, y) (x = min(x, y))
#define limit(x, l, r) max(l, min(x, r)) // x re [l,r] range e ane
#define lims(x, l, r) (x = max(l, min(x, r)))
#define isin(x, l, r) ((l) <= (x) && (x) <= (r)) // depennds
#define pcnt __builtin_popcountll
#define snuke srand((unsigned)clock() + (unsigned)time(NULL)) // i've no idea what on earth it does
#define show(x) cout << #x << " = " << x << endl
#define PQ(T) priority_queue<T, vector<T>, greater<T>>
#define bn(x) ((1 << (x)) - 1)
#define dup(x, y) (((x) + (y) - 1) / (y))
#define drnd(x, y) (((x) + (y) / 2) / (y))
#define newline puts("")
#define tc    \
    int t;    \
    cin >> t; \
    for (int ii = 1; ii <= t; ++ii)
#define tc0    \
    int t = 1; \
    for (int ii = 1; ii <= t; ++ii)
#define nl cout << "\n";
#define gp " "
#define case(ii) cout << "Case #" << ii << ": "

// Graph input macro
#define readgraph(arr, edges)         \
    for (int i = 0; i < (edges); i++) \
    {                                 \
        int a, b;                     \
        cin >> a >> b;                \
        arr[a].pb(b);                 \
        arr[b].pb(a);                 \
    }

// String manipulation macros
#define tolower_str(s) transform(all(s), s.begin(), ::tolower)
#define toupper_str(s) transform(all(s), s.begin(), ::toupper)
#define cng_str(s) transform(all(s), s.begin(), [](char c) { return c ^ ' '; })

// Array manipulation macros
#define clr(arr, val) memset(arr, val, sizeof(arr))
inline int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
#define lcm(a, b) ((a) * (b)) / gcd(a, b)

// Optimized inline functions for common operations
inline lli madd(lli a, lli b, lli m = mod)
{
    return (a + b) % m;
}
inline lli msub(lli a, lli b, lli m = mod)
{
    return (a - b + m) % m;
}
inline lli mmul(lli a, lli b, lli m = mod)
{
    return (a * b) % m;
}
inline lli mpow(lli base, lli exp, lli m = mod)
{
    lli res = 1;
    while (exp > 0)
    {
        if (exp & 1)
            res = mmul(res, base, m);
        base = mmul(base, base, m);
        exp >>= 1;
    }
    return res;
}
inline lli minv(lli a, lli m = mod)
{
    return mpow(a, m - 2, m);
}

// *****************************************************
// ------------------- CODE STARTS HERE ----------------
// *****************************************************

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    tc
    {

        // plan: binary search to find the value that
        lli n, l, r;
        cin >> n >> l >> r;
        take(p, n, lli);
        srt(p);
        lli cnt = 0;
        for (int i = 0; i < n - 1; i++)
        {
            auto low = lower_bound(p.begin() + i + 1, p.end(), l - p[i]);
            auto high = upper_bound(p.begin() + i + 1, p.end(), r - p[i]);
            cnt += (high - low);
        }
        cout << cnt << endl;
    }
}