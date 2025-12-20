

#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
namespace std{
using namespace __gnu_pbds;
template<typename T>
using ordered_set   =   tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
};
#define PI acos(-1.0)
#ifndef ONLINE_JUDGE
#include "debug.hpp"
#else
#define debug(x)
#define error(...)
#endif
#define int long long
const int mod = 1e9 + 7; //998244353; 
#define all(x) (x).begin(), (x).end()
const long double eps = 1e-10;
#define T long double
int sign(T x) { return (x > eps) - (x < -eps); }
struct PT {
  T x, y;
  PT() { x = 0, y = 0; }
  PT(T x, T y) : x(x), y(y) {}
  PT(const PT &p) : x(p.x), y(p.y)  {}
  PT operator + (const PT &a) const { return PT(x + a.x, y + a.y); }
  PT operator - (const PT &a) const { return PT(x - a.x, y - a.y); }
  PT operator * (const T a) const { return PT(x * a, y * a); }
  friend PT operator * (const T &a, const PT &b) { return PT(a * b.x, a * b.y); }
  PT operator / (const T a) const { return PT(x / a, y / a); }
  bool operator == (PT a) const { return sign(a.x - x) == 0 && sign(a.y - y) == 0; }
  bool operator != (PT a) const { return !(*this == a); }
  bool operator < (PT a) const { return sign(a.x - x) == 0 ? y < a.y : x < a.x; }
  bool operator > (PT a) const { return sign(a.x - x) == 0 ? y > a.y : x > a.x; }
  T norm() { return sqrt(x * x + y * y); }
  T norm2() { return x * x + y * y; }
  PT perp() { return PT(-y, x); }
  T arg() { return atan2(y, x); }
  PT truncate(T r) { // returns a vector with norm r and having same direction
    T k = norm();
    if (!sign(k)) return *this;
    r /= k;
    return PT(x * r, y * r);
  }
};
istream &operator >> (istream &in, PT &p) { return in >> p.x >> p.y; }
ostream &operator << (ostream &out, PT &p) { return out << "(" << p.x << "," << p.y << ")"; }
inline T dot(PT a, PT b) { return a.x * b.x + a.y * b.y; }
inline T dist2(PT a, PT b) { return dot(a - b, a - b); }
inline T dist(PT a, PT b) { return sqrt(dot(a - b, a - b)); }
inline T cross(PT a, PT b) { return a.x * b.y - a.y * b.x; }
inline T cross2(PT a, PT b, PT c) { return cross(b - a, c - a); }
inline int orientation(PT a, PT b, PT c) { return sign(cross(b - a, c - a)); }
PT perp(PT a) { return PT(-a.y, a.x); }
PT rotateccw90(PT a) { return PT(-a.y, a.x); }
PT rotatecw90(PT a) { return PT(a.y, -a.x); }
PT rotateccw(PT a, T t) { return PT(a.x * cos(t) - a.y * sin(t), a.x * sin(t) + a.y * cos(t)); }
PT rotatecw(PT a, T t) { return PT(a.x * cos(t) + a.y * sin(t), -a.x * sin(t) + a.y * cos(t)); }
T rad_to_deg(T r) { return (r * 180.0 / PI); }
T deg_to_rad(T d) { return (d * PI / 180.0); }
T get_angle(PT a, PT b) {
  T costheta = dot(a, b) / a.norm() / b.norm();
  return acos(max((T)-1.0, min((T)1.0, costheta)));
}
bool is_point_in_angle(PT b, PT a, PT c, PT p) { // does point p lie in angle <bac
  assert(orientation(a, b, c) != 0);
  if (orientation(a, c, b) < 0) swap(b, c);
  return orientation(a, c, p) >= 0 && orientation(a, b, p) <= 0;
}
bool half(PT p) {
  return p.y > 0.0 || (p.y == 0.0 && p.x < 0.0);
}
void polar_sort(vector<PT> &v) { // sort points in counterclockwise
  sort(v.begin(), v.end(), [](PT a,PT b) {
    return make_tuple(half(a), 0.0, a.norm2()) < make_tuple(half(b), cross(a, b), b.norm2());
  });
}
void polar_sort(vector<PT> &v, PT o) { // sort points in counterclockwise with respect to point o
  sort(v.begin(), v.end(), [&](PT a,PT b) {
    return make_tuple(half(a - o), 0.0, (a - o).norm2()) < make_tuple(half(b - o), cross(a - o, b - o), (b - o).norm2());
  });
}
bool check(PT a,PT b,PT c){
	if(c.y<a.y||c.y>=b.y)return 0;
	int x=b.y-a.y,y=b.x-a.x;
	int x2=c.y-a.y,y2=c.x-a.x;
	return (1ll*x*y2-1ll*x2*y)>0;
}
int dp[501][501]={};
vector<PT>red(501),blue(501);
void action(){
    int n,m;
    cin>>n>>m;
    red.resize(n); 
    for(int i=0;i<n;i++)cin>>red[i];
    for(int i=0;i<m;i++)cin>>blue[i];
    sort(all(red),[&](PT a,PT b){
        return a.y<b.y;
        });
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=0;k<m;k++){
                if(check(red[i],red[j],blue[k])){
                    dp[i][j]++;
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                ans+=(dp[i][j]+dp[j][k]==dp[i][k]);
            }
        }
    }
    cout<<ans<<endl;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t=1;
    for(int ii=1;ii<=t;ii++){
        action();      
    }
} 
