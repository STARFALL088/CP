#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<bool> primes(1000010, 1);
struct pt {
  long double x, y;
  pt() {}
  pt(long double _x, long double _y) : x(_x), y(_y) {}
  pt operator-(const pt &p) const { return pt(x - p.x, y - p.y); }
  long double cross(const pt &p) const { return x * p.y - y * p.x; }
  long double cross(const pt &a, const pt &b) const {
    return (a - *this).cross(b - *this);
  }
};

int sgn(const long double &x) { return x >= 0 ? x ? 1 : 0 : -1; }

bool inter1(long double a, long double b, long double c, long double d) {
  if (a > b)
    swap(a, b);
  if (c > d)
    swap(c, d);
  return max(a, c) <= min(b, d);
}

bool check_inter(const pt &a, const pt &b, const pt &c, const pt &d) {
  if (c.cross(a, d) == 0 && c.cross(b, d) == 0)
    return inter1(a.x, b.x, c.x, d.x) && inter1(a.y, b.y, c.y, d.y);
  return sgn(a.cross(b, c)) != sgn(a.cross(b, d)) &&
         sgn(c.cross(d, a)) != sgn(c.cross(d, b));
}
void action() {
  long double xl, yl, xr, yr;
  cin >> xl >> yl >> xr >> yr;
  pt a(xl, yl), b(xr, yr);
  long double x1,y1,x2,y2;
  cin>>x1>>y1>>x2>>y2;
  pt c(x1,y1),d(x2,y2);
  cout<<(check_inter(a, b, c, d)?"STOP":"OK")<<endl;
}
signed main() {

  int t;
  cin >> t;
  for (int _ = 1; _ <= t; _++)
    action();
}