#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
  int t;
  cin >> t;
  for (int _ = 1; _ <= t; _++) {
    cout << "Case " << _ << ": ";
    int n;
    cin >> n;
    vector<int> p(n);
    for (auto &i : p)
      cin >> i;
    string s;
    int flag = 0;
    for (auto i : p) {
      if (i % 2 == 0)
        flag = 1;
      if (flag == 1) {
        if (i % 2 )
          s.push_back('0');
        else
          s.push_back('1');
      }
    }
    cout << s << endl;
  }
}