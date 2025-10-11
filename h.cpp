#include <numeric>
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include <bits/stdc++.h>
using namespace std;

// Type definitions
typedef long long ll;
typedef long long lli;

// Constants
const lli mod = 1e9 + 7; // 998244353;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rev(x) reverse(all(x))
#define srt(x) sort(all(x))

#define dup(x, y) (((x) + (y) - 1) / (y))
#define drnd(x, y) (((x) + (y) / 2) / (y))
#define nl cout << endl;
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;
#define lg(r, n) (lli)(log2l(n) / log2l(r))
#define tc                                                                     \
  int t;                                                                       \
  cin >> t;                                                                    \
  for (int ii = 1; ii <= t; ++ii)
#define tc0                                                                    \
  int t = 1;                                                                   \
  for (int ii = 1; ii <= t; ++ii)
#define gp " "
#define case(ii) cout << "Case " << ii << ": "
#define freopen                                                                \
  freopen("input.txt", "r", stdin);                                            \
  freopen("output.txt", "w", stdout);

// Graph input macro

// *****************************************************
// ------------------- CODE STARTS HERE ----------------
// *****************************************************
lli MAXN = 1e7;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<bool> primes(MAXN, 1);
  primes[0] = primes[1] = 0;
  for (int i = 2; i * i <= MAXN; i++) {
    if (primes[i] == 1) {
      for (int j = i * i; j <= MAXN; j += i) {
        primes[j] = 0;
      }
    }
  }
  vector<ll> p;

  for (int i = 0; i <= MAXN; i++)
    if (primes[i])
      p.push_back(i);

  lli a, b;
  while (cin >> a >> b) {
    if (a == 0 and b == 0)
      return 0;
    lli ans = 0;
    for (int i = 1; i < 18; i++) {
      lli l = lg(i, a - 1);
      lli r = lg(i, b - 1);
      ans +=
    }
  }
}