#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include <bits/stdc++.h>
using namespace std;

// Type definitions
typedef long long ll;
typedef long long lli;
typedef long double lld;
typedef pair<lli, lli> pii;
typedef pair<lli, lli> pll;
typedef vector<lli> vi;
typedef vector<vi> vvi;
typedef vector<lli> vll;
typedef vector<vll> vvl;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<vc> vvc;

// Constants
const lli mod = 1e9 + 7;
const lli MAXN = 1e6;
const double eps = 1e-10;
const lli LINF = 1001002003004005006ll;
const lli INF = 1001001001;
const lli MX = 200005;
constexpr lli dx[] = {0, 0, 1, -1};
constexpr lli dy[] = {1, -1, 0, 0};
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
#define F first
#define S second
#define pi acos(-1.0)
#define sq(x) ((x) * (x))
#define issq(x) (((lli)(sqrt((x)))) * ((lli)(sqrt((x)))) == (x))
#define lg(r, n) (lli)(log2(n) / log2(r))
#define setpre(n) fixed << setprecision(n)
#define UNIQUE(a) (a).erase(unique(all(a)), (a).end())
#define debug(x)              \
    cerr << #x << " = [ ";    \
    for (const auto &val : x) \
        cerr << val << " ";   \
    cerr << "]\n"; // woeks fine for now
#define take(p, n, T) \
    vector<T> p(n);   \
    for (auto &i : p) \
        cin >> i;
#define input(x)      \
    for (auto &i : x) \
    cin >> i
#define prlli(x)          \
    for (auto &i : x)     \
        cout << i << " "; \
    cout << "\n"

#define arrsum(arr) std::accumulate(arr.begin(), arr.end(), 0LL)
#define error(args...)                           \
    {                                            \
        string _s = #args;                       \
        replace(_s.begin(), _s.end(), ',', ' '); \
        stringstream _ss(_s);                    \
        istream_iterator<string> _it(_ss);       \
        err(_it, args);                          \
    }

void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}
// Loop macros
#define loop(i, n) for (lli i = 0; i < (n); ++i)
#define rloop(i, n) for (lli i = (n) - 1; i >= 0; --i)
#define sloop(i, s, t) for (lli i = s; i < t; ++i)

// Utility macros
#define maxs(x, y) (x = max(x, y))
#define mins(x, y) (x = min(x, y))
#define limit(x, l, r) max(l, min(x, r))
#define lims(x, l, r) (x = max(l, min(x, r)))
#define isin(x, l, r) ((l) <= (x) && (x) <= (r))
#define pcnt __builtin_popcountll
#define snuke srand((unsigned)clock() + (unsigned)time(NULL))
#define show_var(x) cout << #x << " = " << x << endl
#define PQ(T) priority_queue<T, vector<T>, greater<T>>
#define bn(x) ((1 << (x)) - 1)
#define dup(x, y) (((x) + (y) - 1) / (y))
#define drnd(x, y) (((x) + (y) / 2) / (y))
#define newline puts("")
#define YES puts("YES")
#define NO puts("NO")
#define tc    \
    lli t;    \
    cin >> t; \
    for (lli ii = 1; ii <= t; ++ii)
#define tc0    \
    lli t = 1; \
    for (lli ii = 1; ii <= t; ++ii)
#define nl cout << "\n";
#define gp " "
#define case(ii) cout << "Case " << ii << ": "
#define freopen                       \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
// Graph input macro
#define readgraph(arr, edges)         \
    for (lli i = 0; i < (edges); i++) \
    {                                 \
        lli a, b;                     \
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
#define lcm(a, b) ((a) * (b)) / gcd(a, b)

inline lli madd(lli a, lli b, lli m = mod) { return (a + b) % m; }
inline lli msub(lli a, lli b, lli m = mod) { return (a - b + m) % m; }
inline lli mmul(lli a, lli b, lli m = mod) { return (a * b) % m; }
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
inline lli minv(lli a, lli m = mod) { return mpow(a, m - 2, m); }

// *****************************************************
// ------------------- CODE STARTS HERE ----------------
// *****************************************************
void build(lli idx, lli low, lli high, lli arr[], lli seg[])
{
    if (low == high)
    {
        seg[idx] = arr[low];
        return;
    }
    lli mid = (low + high) >> 1;
    build(2 * idx + 1, low, mid, arr, seg);
    build(2 * idx + 2, mid + 1, high, arr, seg);
    seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
}
lli query(lli idx, lli low, lli high, lli l, lli r, lli seg[])
{
    // no overlap
    if (r < low || high < l)
        return 0;
    // complete overlap
    if (low >= l && high <= r)
        return seg[idx];

    lli mid = (low + high) >> 1;
    lli left = query(2 * idx + 1, low, mid, l, r, seg);
    lli right = query(2 * idx + 2, mid + 1, high, l, r, seg);
    return left + right;
}
void update(lli idx, lli low, lli high, lli pos, lli val, lli seg[])
{
    if (low == high)
    {
        seg[idx] = val;
        return;
    }
    lli mid = (low + high) >> 1;
    if (pos <= mid)
        update(2 * idx + 1, low, mid, pos, val, seg);
    else
        update(2 * idx + 2, mid + 1, high, pos, val, seg);
    seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    tc0
    {
        lli n, q;
        cin >> n >> q;
        lli arr[n];
        lli seg[4 * n];
        for (lli i = 0; i < n; i++)
            cin >> arr[i];
        build(0, 0, n - 1, arr, seg);
        // cout<<seg[0]<<endl;
        while (q--)
        {
            lli type;
            cin >> type;
            if (type == 1)
            {
                lli pos, val;
                cin >> pos >> val;
                update(0, 0, n - 1, --pos, val, seg);
                arr[pos] = val;
            }
            if (type == 2)
            {
                lli l, r;
                cin >> l >> r;
                cout << query(0, 0, n - 1, --l, --r, seg) << endl;
            }
        }
    }
}