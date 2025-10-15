#include <bits/stdc++.h>
using namespace std;
#define int long long
#define lld long double

lld f(vector<int> &p, vector<lld> &pre, lld sum, int l, int r, int idx,
      lld tar) {
  cerr << idx << " " << l << " " << r << endl;

  lld up = pre[idx] - pre[l - 1];
  lld down = pre[r] - pre[idx];
  lld tot = up - down;
  // cerr << tot << " " << tar << endl;
  return tot;
}
signed main() {
  int n, q;
  cin >> n >> q;
  int flag = 0;
  vector<int> p(n, 0);
  vector<lld> pre(n + 1, 0.0);
  for (int i = 0; i < n; i++)
    cin >> p[i];
  // for (int i = 0; i < n; i++) {
  //   if (p[i] == 0)
  //     flag = 1;
  // }
  pre[0] = 0; // logl(p[0]);
  for (int i = 1; i <= n; i++) {
    pre[i] += pre[i - 1] + logl(p[i - 1]);
  }
  // for(auto i:pre)cerr<<i<<" ";

  for (int i = 1; i <= q; i++) {
    int l, r;
    lld pw, k;
    int m;
    cin >> l >> r >> pw >> m >> k;
    // if (flag == 1) {
    //   cout << "NO" << endl;
    //   continue;
    // }
    lld tar = k * logl(m);
    int ans = -1;
    int mid;
    int lo=l,hi=r-1;

    while (lo<=hi) {
      mid = (lo + hi) >> 1LL;
      // cerr<<"mid= "<<mid<<endl;
      if (pw * f(p, pre, pre.back(), l, r, mid, tar) >= tar) {
        ans = mid;
        hi = mid - 1;
      } else {
        lo = mid + 1;
      }
    }
    if (ans == -1)
      cout << "NO" << endl;
    else
      cout << "YES" << endl << ans << endl;
  }
}
