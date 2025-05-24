#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include <bits/stdc++.h>
using namespace std;

// Type definitions
typedef long long lli;
typedef long double lld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<lli> vll;
typedef vector<bool> vb;
typedef vector<string> vs;

// Constants
const lli mod = 1e9 + 7;
const lli MAXN = 1e6;
const double eps = 1e-10;
const lli LINF = 1001002003004005006ll;
const int INF = 1001001001;
const int MX = 200005;
constexpr int dx[] = {0, 0, 1, -1};
constexpr int dy[] = {1, -1, 0, 0};
const string ny[] = {"NO", "YES"};

// Macros
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rev(x) reverse(all(x))
#define srt(x) sort(all(x))
#define pb push_back
#define F first
#define S second
#define pi acos(-1.0)
#define sq(x) ((x) * (x))
#define setpre(n) fixed << setprecision(n)
#define UNIQUE(a) (a).erase(unique(all(a)), (a).end())
#define input(x) for (auto &i : x) cin >> i
#define print(x) for (auto &i : x) cout << i << " "; cout << "\n"
#define arrsum(arr) std::accumulate(arr.begin(), arr.end(), 0LL)

// Loop macros
#define loop(i, n) for(int i = 0; i < (n); ++i)
#define rloop(i,n) for(int i = (n)-1; i >= 0; --i)
#define sloop(i,s,t) for (int i = s; i < t; ++i)

// Utility macros
#define maxs(x, y) (x = max(x, y))
#define mins(x, y) (x = min(x, y))
#define limit(x, l, r) max(l, min(x, r))
#define lims(x, l, r) (x = max(l, min(x, r)))
#define isin(x, l, r) ((l) <= (x) && (x) < (r))
#define pcnt __builtin_popcountll
#define snuke srand((unsigned)clock() + (unsigned)time(NULL))
#define show(x) cout << #x << " = " << x << endl
#define PQ(T) priority_queue<T, vector<T>, greater<T>>
#define bn(x) ((1 << (x)) - 1)
#define dup(x, y) (((x) + (y) - 1) / (y))
#define newline puts("")
#define tc int t; cin >> t; for (int ii = 1; ii <= t; ++ii)
#define nl cout << "\n";
#define case(ii) cout << "Case " << ii << ": "

// Graph input macro
#define readgraph(arr, edges) \
    for (int i = 0; i < (edges); i++) { \
        int a, b; \
        cin >> a >> b; \
        arr[a].pb(b); \
        arr[b].pb(a); \
    }

// String manipulation macros
#define tolower_str(s) transform(all(s), s.begin(), ::tolower)
#define toupper_str(s) transform(all(s), s.begin(), ::toupper)
#define cng_str(s) transform(all(s), s.begin(), [](char c) { return c ^ ' '; })

// Array manipulation macros
#define clr(arr, val) memset(arr, val, sizeof(arr))
inline int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
#define lcm(a, b) ((a) * (b)) / gcd(a, b)

// Optimized inline functions for common operations
inline lli madd(lli a, lli b, lli m = mod) {
    return (a + b) % m;
}
inline lli msub(lli a, lli b, lli m = mod) {
    return (a - b + m) % m;
}
inline lli mmul(lli a, lli b, lli m = mod) {
    return (a * b) % m;
}
inline lli mpow(lli base, lli exp, lli m = mod) {
    lli res = 1;
    while (exp > 0) {
        if (exp & 1) res = mmul(res, base, m);
        base = mmul(base, base, m);
        exp >>= 1;
    }
    return res;
}
inline lli minv(lli a, lli m = mod) {
    return mpow(a, m - 2, m);
}


// *****************************************************
// ------------------- CODE STARTS HERE ----------------
// *****************************************************
vector<lli>primes(MAXN,-1);
void sieve() {
    for (lli i = 2; i * i <= MAXN; i++) {
        if (primes[i] == -1) {
            for (lli j = i * i; j <= MAXN; j += i) {
                if (primes[j] == -1) primes[j] = i;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    sieve();

    int size,t;
    cin>>size>>t;
    vector<lli>p(size);
    for(int i=0; i<size; i++) cin>>p[i];
    sort(p.begin(),p.end());
    while(t--) {
        lli a;
        cin>>a;
        if(std::binary_search(p.begin(),p.end(),a)) {
            cout << "0" << endl;
            continue;
        }
        auto it=std::upper_bound(p.begin(),p.end(),a) - p.begin()-1;
        //cout << it<<endl;
        if(it%2==0) cout << "NEGATIVE" << endl;
        else if(it==-1 && size&1) cout << "NEGATIVE" << endl;
        else cout << "POSITIVE" << endl;
    }
}