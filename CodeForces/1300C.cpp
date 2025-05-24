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
const lli mod = 1e9 + 7;
// const lli MAXN = 1e6;
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
#define F first
#define S second
#define pi acos(-1.0)
#define sq(x) ((x) * (x))
#define issq(x) (((lli)(sqrt((x)))) * ((lli)(sqrt((x)))) == (x))
#define lg(r, n) (int)(log2(n) / log2(r))
#define setpre(n) fixed << setprecision(n)
#define UNIQUE(a) (a).erase(unique(all(a)), (a).end())
#define debug(x)              \
    cerr << #x << " = [ ";    \
    for (const auto &val : x) \
        cerr << val << " ";   \
    cerr << "]\n"; // it works fine for now
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

// Utility functions
inline lli gcd(lli a, lli b)
{
    return b == 0 ? a : gcd(b, a % b);
}
#define lcm(a, b) ((a) * (b)) / gcd(a, b)

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
    tc0
    {
        // 1 0 --> 1   a &(!b) :) may be
        // baki sob zero
        lli n;
        cin >> n;
        take(p, n, lli);
        // sort(all(p),cmp);//lamda pari na :)

        // idea: jedar msd 1 aage seta first e dile max asbo
        // w8 max tar set bit 1st e thate na -_-
        // ok na baki sbar 0 lagbe
        lli cnt=0,x=0;
       srt(p);rev(p);
        for(int i=31;i>=0;i--){
            cnt=0;
            for(int j=0;j<n;j++)if(p[j] & (1 << i)){cnt++;x=j;}
            if(cnt==1)break;
        }
        if(cnt==1)swap(p[0],p[x]);
        print(p);
    }
}
