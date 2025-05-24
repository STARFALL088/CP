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
typedef pair<ll, ll> pii;
typedef pair<lli, lli> pll;
typedef vector<ll> vi;
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
const ll INF = 1001001001;
const ll MX = 200005;
constexpr ll dx[] = {0, 0, 1, -1};
constexpr ll dy[] = {1, -1, 0, 0};
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
    for (const auto &val : x) \
        cout << val << " ";   \
    cout << endl;
// Loop macros
#define loop(i, n) for (ll i = 0; i < (n); ++i)
#define rloop(i, n) for (ll i = (n) - 1; i >= 0; --i)
#define sloop(i, s, t) for (ll i = s; i < t; ++i)

// Utility macros
#define arrsum(arr) std::accumulate(arr.begin(), arr.end(), 0LL)
#define maxs(x, y) (x = max(x, y))
#define mins(x, y) (x = min(x, y))
template <class T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b)
{
    if (a > b)
    {
        a = b;
        return 1;
    }
    return 0;
}
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
#define nl cout << endl;
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;
#define tc    \
    ll t;     \
    cin >> t; \
    for (ll ii = 1; ii <= t; ++ii)
#define tc0   \
    ll t = 1; \
    for (ll ii = 1; ii <= t; ++ii)
#define gp " "
#define case(ii) cout << "Case " << ii << ": "
#define freopen                       \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
// Graph input macro
#define readgraph(arr, edges)        \
    for (ll i = 0; i < (edges); i++) \
    {                                \
        ll a, b;                     \
        cin >> a >> b;               \
        arr[a].pb(b);                \
        arr[b].pb(a);                \
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
class segtree
{
    vll seg;

public:
    segtree(ll n)
    {
        seg.resize(4 * n + 1);
    }

    void build(ll idx, ll low, ll high, vll &arr)
    {
        if (low == high)
        {
            seg[idx] = arr[low];
            return;
        }
        ll mid = (low + high) >> 1;
        build(2 * idx + 1, low, mid, arr);
        build(2 * idx + 2, mid + 1, high, arr);
        seg[idx] =maxx( seg[2 * idx + 1] , seg[2 * idx + 2]);
    }
    ll query(ll idx, ll low, ll high, ll l, ll r)
    {
        // no overlap
        if (l > high || r < low)
            return 0;
        // complete ovarlap
        if (l <= low && r >= high)
            return seg[idx];

        ll mid = (low + high) >> 1;
        ll left = query(2 * idx + 1, low, mid, l, r);
        ll right = query(2 * idx + 2, mid + 1, high, l, r);
        return maxx(left , right);
    }
};
// Function to compute Euler Totient Function for all numbers up to n using Sieve
std::vector<ll> eulerTotientSieve(ll n = MAXN)
{
    std::vector<ll> phi(n + 1); // Vector to store Euler Totient values

    // Initialize the phi array
    for (ll i = 0; i <= n; i++)
    {
        phi[i] = i; // Initially, phi[i] = i
    }

    // Apply Sieve-like approach to compute phi
    for (ll p = 2; p <= n; p++)
    {
        // If phi[p] == p, then p is a prime number
        if (phi[p] == p)
        {
            phi[p] = p - 1; // For a prime p, phi(p) = p - 1

            // Update all multiples of p
            for (ll multiple = 2 * p; multiple <= n; multiple += p)
            {
                phi[multiple] = (phi[multiple] / p) * (p - 1);
            }
        }
    }

    return phi;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    tc0
    {
        ll n, q;
        cin >> n >> q;
        vll p1 = eulerTotientSieve(n);
        vll p;
        for (int i = 1; i <= n; i++)
            p.pb(p1[i]);

        segtree a(n);
        a.build(0, 0, n - 1, p);

        // loop(i,n)cout<<p[i]<<gp;
        while (q--)
        {
            lli l, r;
            cin >> l >> r;
            --l, --r;
            cout << (a.query(0, 0, n - 1, l, r)) << endl;
        }
    }
}