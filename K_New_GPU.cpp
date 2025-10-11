#include <bits/stdc++.h>
#include <climits>
using namespace std;
#define ll long long
#define int long long
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ll a, b, p;
  cin >> a >> b >> p;
  ll ans = 0;

    ll lo = 0;
    double hi = 1LL<<60 ;
    
    int z = 0;
    while (lo <= hi) {
      z++;
      ll mid = lo + (hi - lo) / 2;
    //   mid=ceil(mid);
      double q =1.0* a * powl(double(mid), 1.0 / 3) + 1.0*b * powl(double(mid), 1.0 / 2);

      if (q < p) {
        lo = mid + 1;
      } else {
        ans = mid;
        hi = mid - 1;
      }
    }
    cout << ans << endl;


  return 0;
}