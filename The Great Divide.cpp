
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
namespace std {
using namespace __gnu_pbds;
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
};

#ifndef ONLINE_JUDGE
#include "debug.hpp"
#else
#define debug(x)
#define error(...)
#endif
#define int long long
const int mod = 1e9 + 7; // 998244353;
#define all(x) (x).begin(), (x).end()
#define T int
#define PI acos(-1.0)
long double eps = 10e-10;
int sign(T x) { return (x > eps) - (x < -eps); }
struct PT {
  T x, y;
  PT() { x = 0, y = 0; }
  PT(T x, T y) : x(x), y(y) {}
  PT(const PT &p) : x(p.x), y(p.y) {}
  PT operator+(const PT &a) const { return PT(x + a.x, y + a.y); }
  PT operator-(const PT &a) const { return PT(x - a.x, y - a.y); }
  PT operator*(const T a) const { return PT(x * a, y * a); }
  friend PT operator*(const T &a, const PT &b) { return PT(a * b.x, a * b.y); }
  PT operator/(const T a) const { return PT(x / a, y / a); }
  bool operator==(PT a) const {
    return sign(a.x - x) == 0 && sign(a.y - y) == 0;
  }
  bool operator!=(PT a) const { return !(*this == a); }
  bool operator<(PT a) const { return sign(a.x - x) == 0 ? y < a.y : x < a.x; }
  bool operator>(PT a) const { return sign(a.x - x) == 0 ? y > a.y : x > a.x; }
  T norm() { return sqrt(x * x + y * y); }
  T norm2() { return x * x + y * y; }
  PT perp() { return PT(-y, x); }
  T arg() { return atan2(y, x); }
  PT truncate(T r) { // returns a vector with norm r and having same direction
    T k = norm();
    if (!sign(k))
      return *this;
    r /= k;
    return PT(x * r, y * r);
  }
};
istream &operator>>(istream &in, PT &p) { return in >> p.x >> p.y; }
ostream &operator<<(ostream &out, PT &p) {
  return out << "(" << p.x << "," << p.y << ")";
}
inline T dot(PT a, PT b) { return a.x * b.x + a.y * b.y; }
inline T dist2(PT a, PT b) { return dot(a - b, a - b); }
inline T dist(PT a, PT b) { return sqrt(dot(a - b, a - b)); }
inline T cross(PT a, PT b) { return a.x * b.y - a.y * b.x; }
inline T cross2(PT a, PT b, PT c) { return cross(b - a, c - a); }
inline int orientation(PT a, PT b, PT c) { return sign(cross(b - a, c - a)); }
PT perp(PT a) { return PT(-a.y, a.x); }
PT rotateccw90(PT a) { return PT(-a.y, a.x); }
PT rotatecw90(PT a) { return PT(a.y, -a.x); }
PT rotateccw(PT a, T t) {
  return PT(a.x * cos(t) - a.y * sin(t), a.x * sin(t) + a.y * cos(t));
}
PT rotatecw(PT a, T t) {
  return PT(a.x * cos(t) + a.y * sin(t), -a.x * sin(t) + a.y * cos(t));
}
T rad_to_deg(T r) { return (r * 180.0 / PI); }
T deg_to_rad(T d) { return (d * PI / 180.0); }
T get_angle(PT a, PT b) {
  T costheta = dot(a, b) / a.norm() / b.norm();
  return acos(max((T)-1.0, min((T)1.0, costheta)));
}
bool is_point_in_angle(PT b, PT a, PT c,
                       PT p) { // does point p lie in angle <bac
  assert(orientation(a, b, c) != 0);
  if (orientation(a, c, b) < 0)
    swap(b, c);
  return orientation(a, c, p) >= 0 && orientation(a, b, p) <= 0;
}
bool half(PT p) { return p.y > 0.0 || (p.y == 0.0 && p.x < 0.0); }
void polar_sort(vector<PT> &v) { // sort points in counterclockwise
  sort(v.begin(), v.end(), [](PT a, PT b) {
    return make_tuple(half(a), 0.0, a.norm2()) <
           make_tuple(half(b), cross(a, b), b.norm2());
  });
}
void polar_sort(
    vector<PT> &v,
    PT o) { // sort points in counterclockwise with respect to point o
  sort(v.begin(), v.end(), [&](PT a, PT b) {
    return make_tuple(half(a - o), 0.0, (a - o).norm2()) <
           make_tuple(half(b - o), cross(a - o, b - o), (b - o).norm2());
  });
}

vector<PT> convex_hull(vector<PT> &p) {
  if (p.size() <= 1)
    return p;
  vector<PT> v = p;
  sort(v.begin(), v.end());
  vector<PT> up, dn;
  for (auto &p : v) {
    while (up.size() > 1 && orientation(up[up.size() - 2], up.back(), p) >= 0) {
      up.pop_back();
    }
    while (dn.size() > 1 && orientation(dn[dn.size() - 2], dn.back(), p) <= 0) {
      dn.pop_back();
    }
    up.push_back(p);
    dn.push_back(p);
  }
  v = dn;
  if (v.size() > 1)
    v.pop_back();
  reverse(up.begin(), up.end());
  up.pop_back();
  for (auto &p : up) {
    v.push_back(p);
  }
  if (v.size() == 2 && v[0] == v[1])
    v.pop_back();
  return v;
}
int is_point_in_convex(vector<PT> &p, const PT &x) { // O(log n)
  int n = p.size();
  assert(n >= 3);
  int a = orientation(p[0], p[1], x), b = orientation(p[0], p[n - 1], x);
  if (a < 0 || b > 0)
    return 1;
  int l = 1, r = n - 1;
  while (l + 1 < r) {
    int mid = l + r >> 1;
    if (orientation(p[0], p[mid], x) >= 0)
      l = mid;
    else
      r = mid;
  }
  int k = orientation(p[l], p[r], x);
  if (k <= 0)
    return -k;
  if (l == 1 && a == 0)
    return 0;
  if (r == n - 1 && b == 0)
    return 0;
  return -1;
}

bool seg_seg_intersection(PT a, PT b, PT c, PT d) {
  T oa = cross2(c, d, a), ob = cross2(c, d, b);
  T oc = cross2(a, b, c), od = cross2(a, b, d);
  if (oa * ob < 0 && oc * od < 0) {
    return 1;
  } else
    return 0;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;

  while (1) {
    cin >> n >> m;
    if (n==0 and m==0)break;
    vector<PT> a(n), b(m);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    for (int i = 0; i < m; i++)
      cin >> b[i];
    bool ans = 1;
    
    vector<PT> ca = convex_hull(a), cb = convex_hull(b);
    
    int n1 = ca.size(), n2 = cb.size();
    if(n2>=3)for (auto point : ca) {
      if (is_point_in_convex(cb, point) != 1) {
        ans = 0;
      }
    }
    if(n1>=3)for (auto point : cb) {
      if (is_point_in_convex(ca, point) != 1) {
        ans = 0;
      }
    }
    for (int i = 0; i < n1; i++) {
      for (int j = 0; j < n2; j++) {
        if (seg_seg_intersection(ca[i], ca[(i + 1) % n1], cb[j],
                                 cb[(j + 1) % n2]))
          ans = 0;
      }
    }
    cout << (ans ? "Yes" : "No") << endl;
  }
}
