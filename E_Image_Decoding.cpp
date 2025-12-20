#include "debug.hpp"
#include <bits/stdc++.h>
#include <cstdio>
#include <cstdlib>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <sstream>
using namespace std;
#define ll long long int

void action() {
  bool xyz = 0;
  int n;
  while (cin >> n) {
    if (n == 0)
      return;

    if (xyz)
      cout << endl;
    xyz = 1;
    set<ll> st;
    stringstream ans;
    cin.ignore();
    while (n--) {
      string s;

      getline(cin, s);
      char cur;
      stringstream ss(s);

      ss >> cur;

      ll cnt = 0;
      for (auto i : s)
        cnt += i == ' ';
      ll sum = 0;

      while (cnt--) {
        int val;
        ss >> val;
        sum += val;
        while (val--) {
          ans << cur;
        }
        cur ^= ('#' ^ '.');
      }
      // error(sum);
      st.insert(sum);
      ans << endl;
    }
    // debug(st);
    if (st.size() != 1)
      ans << "Error decoding image" << endl;
    cout << ans.str();
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int tc;
  tc = 1;
  // cin >> tc;

  while (tc--) {
    // solve();
    action();
  }

  return 0;
}
