#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  for (int _ = 1; _ <= t; _++) {
    cout << "Case " << _ << ":" << endl;
    ;
    string s;
    cin >> s;
    int n = s.size();
    set<int> st;
    st.insert(0);
    st.insert(n);
    for (int i = 1; i < n; i++) {
      if (s[i] != s[i - 1])
        st.insert(i);
    }

    int q;
    cin >> q;
    while (q--) {
      int type;
      cin >> type;
      if (type == 1) {
        int tar;
        cin >> tar;
        auto it = st.upper_bound(tar);
        cout << (*it--) - (*it) << endl;
      } else {
        int x;
        cin >> x;
        st.insert(x);
        st.insert(x + 1);
      }
    }
  }
}