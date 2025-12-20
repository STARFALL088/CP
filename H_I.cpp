#include <bits/stdc++.h>
using namespace std;


#define fast_io() ios::sync_with_stdio(false); cin.tie(nullptr)
#define FOR(a, b, c) for (int i = (a); i < (b); i += (c))
#define rep1(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define each(x, v) for (auto &x : (v))
#define trav(x, v) for (auto &x : (v))
#define testcase(tt) int tt; cin >> tt; while (tt--) solve();
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)((x).size())
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define sortv(v) sort(all(v))
#define rev(v) reverse(all(v))
#define UNIQUE(v) (v).erase(unique(all(v)), (v).end())
#define uniq(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define lb(v, x) (int)(lower_bound(all(v), (x)) - (v).begin())
#define ub(v, x) (int)(upper_bound(all(v), (x)) - (v).begin())
#define bit(n, i) (((n) >> (i)) & 1)
#define set_bit(n, i) ((n) |= (1LL << (i)))
#define clr_bit(n, i) ((n) &= ~(1LL << (i)))
#define toggle_bit(n, i) ((n) ^= (1LL << (i)))
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll
#define max3(a, b, c) max((a), max((b), (c)))
#define min3(a, b, c) min((a), min((b), (c)))
#define YES cout << "YES\n"
#define NO  cout << "NO\n"
#define umap unordered_map
#define uset unordered_set

// Vector I/O
#define VECTOR_IO \
template <typename T> \
istream& operator>>(istream &in, vector<T> &v) { for (auto &x : v) in >> x; return in; } \
template <typename T> \
ostream& operator<<(ostream &out, const vector<T> &v) { for (const auto &x : v) out << x << ' '; return out; }
VECTOR_IO

// set I/O (expects count first in input)
#define SET_IO \
template <typename T> \
istream& operator>>(istream &in, set<T> &s) { int n; in >> n; s.clear(); for (int i = 0; i < n; ++i) { T x; in >> x; s.insert(x); } return in; } \
template <typename T> \
ostream& operator<<(ostream &out, const set<T> &s) { for (const auto &x : s) out << x << ' '; return out; }
SET_IO

// unordered_set I/O (expects count first in input)
#define USET_IO \
template <typename T> \
istream& operator>>(istream &in, unordered_set<T> &s) { int n; in >> n; s.clear(); for (int i = 0; i < n; ++i) { T x; in >> x; s.insert(x); } return in; } \
template <typename T> \
ostream& operator<<(ostream &out, const unordered_set<T> &s) { for (const auto &x : s) out << x << ' '; return out; }
USET_IO

// multiset I/O (expects count first in input)
#define MSET_IO \
template <typename T> \
istream& operator>>(istream &in, multiset<T> &s) { int n; in >> n; s.clear(); for (int i = 0; i < n; ++i) { T x; in >> x; s.insert(x); } return in; } \
template <typename T> \
ostream& operator<<(ostream &out, const multiset<T> &s) { for (const auto &x : s) out << x << ' '; return out; }
MSET_IO

#ifdef LOCAL
#  include <typeinfo>
#  define DEBUG_TYPE(x) cerr << "Type of " << #x << ": " << typeid(x).name() << "\n";
#else
#  define DEBUG_TYPE(x)
#endif

#define matrix(T) vector<vector<T>>

#ifdef LOCAL
#  define dbg(x) cerr << #x << " = " << (x) << "\n"
template <typename T> void dbg_vec(const T& container) { cerr << #container << " = "; for (auto x : container) cerr << x << ' '; cerr << "\n"; }
template <typename T> void debug_out(T t) { cerr << t << "\n"; }
template <typename T, typename... Ts> void debug_out(T t, Ts... ts) { cerr << t << ' '; debug_out(ts...); }
#  define dbg_multi(...) { cerr << "[" << #__VA_ARGS__ << "]: "; debug_out(__VA_ARGS__); }
#else
#  define dbg(x)
#  define dbg_vec(x)
#  define dbg_multi(...)
#endif

#define sqr(x) ((x) * (x))
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using v   = vector<int>;
using vll = vector<ll>;
using vpi = vector<pii>;
using vv  = vector<vector<int>>;

const int MOD = 1000003; // keep as your original MOD
const int INF = 1000000000;
const double EPS = 1e-9;
const ll LINF = (ll)1e18;

ll gcdll(ll a, ll b) { return b == 0 ? a : gcdll(b, a % b); }
ll lcmll(ll a, ll b) { return (a / gcdll(a, b)) * b; }

ll mod_pow(ll base, ll exp, ll mod = MOD) {
  ll res = 1;
  while (exp) {
    if (exp & 1) res = (res * base) % mod;
    base = (base * base) % mod;
    exp >>= 1;
  }
  return res;
}

vector<bool> prime_sieve(int n) {
  vector<bool> is_prime(n + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i * i <= n; ++i) if (is_prime[i])
    for (int j = i * i; j <= n; j += i) is_prime[j] = false;
  return is_prime;
}

template <typename T>
vector<T> prefixSum(const vector<T>& arr) {
  vector<T> pre(arr.size() + 1, 0);
  for (size_t i = 0; i < arr.size(); ++i) pre[i + 1] = pre[i] + arr[i];
  return pre;
}

bool isPalindrome(const vector<int>& vec) {
  int l = 0, r = (int)vec.size() - 1;
  while (l < r) {
    if (vec[l] != vec[r]) return false;
    ++l; --r;
  }
  return true;
}

ll power(ll a, ll b) { ll ans = 1; while (b--) ans *= a; return ans; }

bool is_prime(int n) {
  if (n <= 1) return false;
  for (int i = 2; 1LL * i * i <= n; ++i) if (n % i == 0) return false;
  return true;
}

ll fac(ll n) { ll ans = 1; while (n) { ans *= n; --n; } return ans; }

inline ll mod_add(ll a, ll b, ll mod) { return (a % mod + b % mod) % mod; }
inline ll mod_sub(ll a, ll b, ll mod) { return (a % mod - b % mod + mod) % mod; }
inline ll mod_mul(ll a, ll b, ll mod) { return ((a % mod) * (b % mod)) % mod; }

ll mod_exp(ll a, ll b, ll mod) {
  if (b == 0) return 1;
  ll res = mod_exp(a, b / 2, mod);
  res = mod_mul(res, res, mod);
  if (b & 1) res = mod_mul(res, a, mod);
  return res;
}

ll mod_inv(ll b, ll mod) { return mod_exp(b, mod - 2, mod); } // mod must be prime
ll mod_div(ll a, ll b, ll mod) { return mod_mul(a, mod_inv(b, mod), mod); }

// nCr utilities
ll fact[900005];
void factorial(ll mod) {
  fact[0] = 1;
  for (ll i = 1; i <= 900004; ++i) fact[i] = mod_mul(fact[i - 1], i, mod);
}
ll nCr(ll n, ll r, ll mod) {
  if (r < 0 || r > n) return 0;
  return mod_div(fact[n], mod_mul(fact[r], fact[n - r], mod), mod);
}

void solve() {
  // your code here
  ll a,b;cin>>a>>b;
  if(b==2 || b==4){
    cout<<-1<<'\n';return;
  }
  int div=a/(b-2),rem=a%(b-2);
  if(rem==2){
    if(div<2)cout<<-1<<'\n';
    else if(b<=6)cout<<-1<<'\n';
    else {
        ll x=b-4;
        string s((b-2)/2,'('),s2((b-2)/2,')');
        for(int i=0;i<div-2;i++)cout<<s<<s2;
        cout<<string(x/2,'(')<<string(x/2,')')<<"((()))"<<string(x/2,'(')<<string(x/2,')')<<'\n';
    }
  }
  else {
    string s((b-2)/2,'('),s2((b-2)/2,')');
    for(int i=0;i<div;i++){
        cout<<s<<s2;
    }
    cout<<string(rem/2,'(')<<string(rem/2,')')<<'\n';
  }
}

int main() {
  fast_io();
  //solve();
   testcase(tt);
  return 0;
}