#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
namespace std
{
    using namespace __gnu_pbds;
    template <typename T>
    using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
};

#ifndef ONLINE_JUDGE
#define debug(x)              \
    cerr << #x << " = [ ";    \
    for (const auto &val : x) \
        cerr << val << " ";   \
    cerr << "]\n";
#define error(args...)                           \
    {                                            \
        string _s = #args;                       \
        replace(_s.begin(), _s.end(), ',', ' '); \
        stringstream _ss(_s);                    \
        istream_iterator<string> _it(_ss);       \
        _err(_it, args);                         \
    }
void _err(istream_iterator<string> it) { cerr << "\n"; }
template <typename T, typename... Args>
void _err(istream_iterator<string> it, T a, Args... args)
{
    cerr << *it << " = " << a << " | ";
    _err(++it, args...);
}
#else
#define debug(...)
#define error(...)
#endif

// Type definitions
typedef long long ll;
typedef long long lli;
typedef long double lld;
using ull = uint64_t;
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
const lli mod1 = 1e9 + 7;
const lli mod2 = 998244353;
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
#define maxx (lli) fmax
#define minn (lli) fmin
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pi acos(-1.0) // 2*asinl(1.0);
#define sq(x) ((x) * (x))
#define issq(x) (((lli)(sqrt((x)))) * ((lli)(sqrt((x)))) == (x))
#define lg(r, n) (lli)(log2l(n) / log2l(r))
#define setpre(n) fixed << setprecision(n)
#define UNIQUE(a) (a).erase(unique(all(a)), (a).end())
#define take(p, n, T) \
    vector<T> p(n);   \
    for (auto &i : p) \
        cin >> i;
#define input(x)      \
    for (auto &i : x) \
    cin >> i
#define print(x)              \
    cerr << #x << " = [ ";    \
    for (const auto &val : x) \
        cout << val << " ";   \
    cerr << "]";              \
    cout << endl;

// Loop macros
#define loop(i, n) for (int i = 0; i < (n); ++i)
#define rloop(i, n) for (int i = (n) - 1; i >= 0; --i)
#define sloop(i, s, t) for (int i = s; i < t; ++i)

// Utility macros
#define arrsum(arr) std::accumulate(arr.begin(), arr.end(), 0LL)
#define maxs(x, y) (x = max(x, y))
#define mins(x, y) (x = min(x, y))
#define limit(x, l, r) max(l, min(x, r))
#define lims(x, l, r) (x = max(l, min(x, r)))
#define isin(x, l, r) ((l) <= (x) && (x) <= (r))
#define pcnt __builtin_popcountll
#define snuke srand((unsigned)clock() + (unsigned)time(NULL))
#define show_var(x) cout << #x << " = " << x << endl
#define PQ(T) priority_queue<T, vector<T>, greater<T>>
#define bn(x) ((1LL << (x - 1)))
#define dup(x, y) (((x) + (y) - 1) / (y))
#define drnd(x, y) (((x) + (y) / 2) / (y))
#define newline cout << endl;
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
#define tc    \
    int t;    \
    cin >> t; \
    for (int ii = 1; ii <= t; ++ii)
#define tc0    \
    int t = 1; \
    for (int ii = 1; ii <= t; ++ii)
#define nl cout << "\n";
#define gp " "
#define case(ii) cout << "Case " << ii << ": "
#define freopen                       \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
// Graph input macro
#define readgraph(arr, edges)         \
    for (int i = 0; i < (edges); i++) \
    {                                 \
        int a, b;                     \
        cin >> a >> b;                \
        arr[a].pb(b);                 \
        arr[b].pb(a);                 \
    }
#define by(x) [](const auto &a, const auto &b) { return a.x < b.x; }
#define tolower_str(s) transform(all(s), s.begin(), ::tolower)
#define toupper_str(s) transform(all(s), s.begin(), ::toupper)
#define cng_str(s) transform(all(s), s.begin(), [](char c) { return c ^ ' '; })
#define clr(arr, val) memset(arr, val, sizeof(arr))

// Utility functions
inline lli gcd(lli a, lli b) { return b == 0 ? a : gcd(b, a % b); }
#define lcm(a, b) (1LL * (a) * (b)) / gcd(a, b)

inline lli madd(lli a, lli b, lli m = mod) { return ((a % m) + (b % m)) % m; }
inline lli msub(lli a, lli b, lli m = mod) { return (((a % m) - (b % m)) % m + m) % m; }
inline lli mmul(lli a, lli b, lli m = mod) { return ((a % m) * (b % m)) % m; }
inline lli mpow(lli base, lli exp, lli m = mod)
{
    lli res = 1LL;
    while (exp > 0)
    {
        if (exp & 1)
            res = mmul(res, base, m);
        base = mmul(base, base, m);
        exp >>= 1LL;
    }
    return res;
}
inline lli minv(lli a, lli m = mod) { return mpow(a, m - 2, m); }

// *****************************************************
// ------------------- CODE STARTS HERE ----------------
// *****************************************************

lli rec(lli n, lli x, lli y) {
    if (n == 1) {
        if (x == 1 && y == 1)
            return 1;
        if (x == 1 && y == 2)
            return 4;
        if (x == 2 && y == 1)
            return 3;
        if (x == 2 && y == 2)
            return 2;
    }
    lli z = (1LL << (n - 1));
    lli m = 1LL << (2 * (n - 1));
    if (x <= z && y <= z)
        return rec(n - 1, x, y);
    if (x > z && y <= z)
        return rec(n - 1, x - z, y) + 2 * m;
    if (x <= z && y > z)
        return 3 * m + rec(n - 1, x, y - z);
    else
        return m + rec(n - 1, x - z, y - z);
}
pll get(lli n, lli d) {
    if (n == 1) {
        if (d == 1)
            return {1, 1};
        if (d == 2)
            return {2, 2};
        if (d == 3)
            return {2, 1};
        if (d == 4)
            return {1, 2};
    }

    lli z = (1LL << (n - 1));
    lli m = 1LL << (2 * (n - 1));

    if (d <= m) {
        pll p = get(n - 1, d);
        return p;
    } else if (d <= 2 * m) {
        pll p = get(n - 1, d - m);
        return {p.first + z, p.second + z};
    } else if (d <= 3 * m) {
        pll p = get(n - 1, d - 2 * m);
        return {p.first + z, p.second};
    } else {
        pll p = get(n - 1, d - 3 * m);
        return {p.first, p.second + z};
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    tc
    {
        lli n, q;
        cin >> n >> q;
        while (q--)
        {
            char _, c;
            cin >> _ >> c;
            if (c == '>')
            {
                lli x, y;
                cin >> x >> y;
                cout << rec(n, x, y) << endl;
            }
            else
            {
                lli d;
                cin >> d;
                pll p = get(n, d);
                cout << p.first << gp << p.second << endl;
            }
        }
    }
}