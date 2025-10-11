#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
#define int long long
signed main() {

  freopen("bisector.in", "r", stdin);
  freopen("bisector.out", "w", stdout);

  vector<int> x(3), y(3);
  for (int i = 0; i < 3; i++) {
    cin >> x[i] >> y[i];
  }

  long double a1 = (y[1] - y[0]), a2 = (y[2] - y[0]), b1 = -(x[1] - x[0]),
              b2 = -(x[2] - x[0]);
  long double c1 = -(x[0] * a1 + y[0] * b1);
  long double c2 = -(x[0] * a2 + y[0] * b2);
  long double z2 = sqrtl(a1 * a1 + b1 * b1);
  long double z1 = sqrtl(a2 * a2 + b2 * b2);
  cout << fixed << setprecision(1) << z1 * a1 + z2 * a2 << " "
       << z1 * b1 + z2 * b2 << " " << z1 * c1 + z2 * c2 << endl;
}