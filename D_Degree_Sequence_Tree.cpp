#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define ll long long
#define int long long
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  int sum = 0;
  vector<int> p(n);
  vector<int> one;
  vector<pair<int, int>> baki;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    if (p[i] == 1)
      one.push_back(i + 1);
    else
      baki.push_back({i + 1, p[i]});
    sum += p[i];
    if (p[i] < 1)
      return cout << -1, 0;
  }
  cerr << sum;
  if (sum != (n - 1) * 2)
    return cout << -1, 0;

  if (n == 2) {
    return cout << 1 << " " << 2, 0;
  }
  vector<pair<int, int>> ans;

  if (baki.size() == 1) {
    for (int i = 0; i < one.size(); i++) {
      cout << one[i] << " " << baki[0].first << endl;
    }
    return 0;
  }
 
  for (int i = 0; i < baki.size() - 1; i++) {
    ans.push_back({baki[i].first, baki[i + 1].first});
  }

  int z = 0;

  for (int i = 0; i < baki.size(); i++) {
    int lage = baki[i].second - 1;
    if (i != 0 and i != baki.size() - 1)
      lage--;
    for (int j = 0; j < lage; j++) {
      ans.push_back({baki[i].first, one[z++]});
    }
  }
  for (auto [i, j] : ans) {
    cout << i << " " << j << endl;
  }
  return 0;
}

// #include <bits/stdc++.h>
// #include <climits>
// #include <vector>
// using namespace std;
// #define ll long long
// #define int long long
// signed main() {
//   ios::sync_with_stdio(0);
//   cin.tie(0);
//   cout.tie(0);
//   int n;
//   cin >> n;
//   vector<ll> v(n);
//   int sum = 0;
//   for (ll i = 0; i < n; i++) {
//     cin >> v[i];
//     sum += v[i];
//     if (v[i] < 1)
//       return cout << -1, 0;
//   }
//   if (sum != (n - 1) * 2)
//     return cout << -1, 0;
//   vector<ll> p;
//   vector<ll> p1;
//   for (ll i = 0; i < n; i++) {
//     if (v[i] > 1) {
//       p.push_back(i + 1);
//     } else {
//       p1.push_back(i + 1);
//     }
//   }
//   //   for (ll i = 0; i < p.size(); i++) {

//   // cout<<p[i]<<" ";}cout<<endl;

//   //    for (ll i = 0; i < p1.size(); i++) {

//   // cout<<p1[i]<<" ";}cout<<endl;

//   for (ll i = 0; i < p.size() - 1; i++) {
//     cout << p[i] << " " << p[i + 1] << endl;
//   }
//   ll indx = 0;
//   for (ll i = 0; i < p.size(); i++)
//   {
//     ll x = v[p[i]];
//     ll y = 2;
//     if(i==0 || i==p.size()-1)
//     {
//         y=1;
//     }
//     cout<<"case: "<<endl;
//     cout<<p[i]<<endl;
//     cout<<y<<" "<<x<<endl;
//     while (y < x-1) {
//       cout << p[i] << " " << p1[indx] << endl;
//       indx++;
//       y++;
//     }
//   }

//   return 0;
// }