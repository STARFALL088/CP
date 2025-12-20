#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
namespace std {
using namespace __gnu_pbds;
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag,
                              tree_order_statistics_node_update>;
template <class key, class value, class cmp = std::less<key>>
using ordered_map =
    tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
}; // namespace std

#ifndef ONLINE_JUDGE
#include "debug.hpp"
#else
#define debug(x)
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
#define F first
#define S second
#define pi acos(-1.0) // 2*asinl(1.0);
#define sq(x) ((x) * (x))
#define issq(x) (((lli)(sqrt((x)))) * ((lli)(sqrt((x)))) == (x))
#define lg(r, n) (lli)(log2l(n) / log2l(r))
#define setpre(n) fixed << setprecision(n)
#define UNIQUE(a) (a).erase(unique(all(a)), (a).end())
#define take(p, n, T)                                                          \
  vector<T> p(n);                                                              \
  for (auto &i : p)                                                            \
    cin >> i;
#define input(x)                                                               \
  for (auto &i : x)                                                            \
  cin >> i
#define print(x)                                                               \
  for (const auto &val : x)                                                    \
    cout << val << " ";                                                        \
  cout << endl;
// Loop macros
#define loop(i, n) for (int i = 0; i < (n); ++i)
#define rloop(i, n) for (int i = (n) - 1; i >= 0; --i)
#define sloop(i, s, t) for (int i = s; i < t; ++i)

// Utility macros
#define arrsum(arr) std::accumulate(arr.begin(), arr.end(), 0LL)
#define maxs(x, y) (x = max(x, y))
#define mins(x, y) (x = min(x, y))
template <class T> bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T> bool chmin(T &a, const T &b) {
  if (a > b) {
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
#define tc                                                                     \
  int t;                                                                       \
  cin >> t;                                                                    \
  for (int ii = 1; ii <= t; ++ii)
#define tc0                                                                    \
  int t = 1;                                                                   \
  for (int ii = 1; ii <= t; ++ii)
#define gp " "
#define Case(ii) cout << "Case " << ii << ": "
// Graph input macro
#define readgraph(arr, edges)                                                  \
  for (int i = 0; i < (edges); i++) {                                          \
    int a, b;                                                                  \
    cin >> a >> b;                                                             \
    arr[a].pb(b);                                                              \
    arr[b].pb(a);                                                              \
  }
#define by(x) [](const auto &a, const auto &b) { return a.x < b.x; }
#define tolower_str(s) transform(all(s), s.begin(), ::tolower)
#define toupper_str(s) transform(all(s), s.begin(), ::toupper)
#define cng_str(s) transform(all(s), s.begin(), [](char c) { return c ^ ' '; })
#define clr(arr, val) memset(arr, val, sizeof(arr))

// Utility functions
inline lli gcd(lli a, lli b) { return b == 0 ? a : gcd(b, a % b); }
#define lcm(a, b) 1LL * (a) * ((b) / gcd(a, b))

inline lli madd(lli a, lli b, lli m = mod) { return ((a % m) + (b % m)) % m; }
inline lli msub(lli a, lli b, lli m = mod) {
  return (((a % m) - (b % m)) % m + m) % m;
}
inline lli mmul(lli a, lli b, lli m = mod) { return ((a % m) * (b % m)) % m; }
inline lli mpow(lli base, lli exp, lli m = mod) {
  lli res = 1LL;
  while (exp > 0) {
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
#define int long long
const int mxN = 1e5;
int a[mxN], t[2 * mxN - 1], lazy[2 * mxN - 1], n;

void build(int v, int tl, int tr) {
  if (tl == tr) {
    t[v] = a[tl];
  } else {
    int tm = (tl + tr) >> 1;

    build(v + 1, tl, tm);
    build(v + 2 * (tm - tl + 1), tm + 1, tr);

    t[v] = max(t[v], t[v + 2 * (tm - tl + 1)]);
  }
}

void push(int v, int tl, int tm) {
  int c1 = v + 1;
  int c2 = v + 2 * (tl - tm + 1);

  t[c1] += lazy[v];
  t[c2] += lazy[v];

  lazy[c1] += lazy[v];
  lazy[c2] += lazy[v];

  lazy[v] = 0;
}

int query(int v, int tl, int tr, int l, int r) {
  if (l > r) {
    return -1e9;
  }

  if (l <= tl && tr <= r) {
    return t[v];
  }

  int tm = (tl + tr) >> 1;

  push(v, tl, tm);

  return max(query(v + 1, tl, tm, l, min(r, tm)),
             query(v + 2 * (tm - tl + 1), tm + 1, tr, max(l, tm + 1), r));
}

void update(int v, int tl, int tr, int l, int r, int addend) {
  if (l > r) {
    return;
  }

  if (l == tl && r == tr) {
    t[v] += addend;
    lazy[v] += addend;
  } else {
    int tm = (tl + tr) >> 1;

    push(v, tl, tm);

    update(v + 1, tl, tm, l, min(r, tm), addend);
    update(v + 2 * (tm - tl + 1), tm + 1, tr, max(l, tm + 1), r, addend);

    t[v] = max(t[v + 1], t[v + 2 * (tm - tl + 1)]);
  }
}

signed main() {
  cin >> n;
  vector<long long> p(n);
  for (auto &i : p)
    cin >> i;
  for (int i = 0; i < n - 1; i++)
    a[i] = abs(a[i] = a[i + 1]);
error("")
  n--;
  build(0, 0, n - 1);

  int q, cmd, l, r, addend;
  cin>>q;

  while (q--) {
    cin >> cmd >> l >> r;
    --l, --r;
    if (cmd == 1) {
      cout << query(0, 0, n - 1, l, r) << endl;
    } else if (cmd == 2) {
      cin>>addend;
      update(0, 0, n - 1, l, r, addend);
    }
  }

  return 0;
}