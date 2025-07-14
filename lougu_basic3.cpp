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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n = 12;
    lli fix,ase = 0;
    lli mom = 0;
    vll p(n + 1, 0);
    bool flag=1;
    for (lli i = 1; i <= n; i++)
        cin >> p[i];
    for (lli i = 1; i <= n; i++)
    {
        ase += 300;
        ase -= p[i];
        mom+=ase/100;
        if (ase < 0)
        {
            fix=i;
           flag=0;
           break;
        }    
        ase %= 100;
        
    }
   if(flag)cout<< mom * 120+ase << endl;
   else cout<<-fix<<endl;
}