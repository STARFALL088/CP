#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define int long long
signed main() {
  int n;
  cin >> n;
  unordered_map<string, int> m;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    m[s]++;
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    if (m.count(s) and m[s]) {

      m[s]--;
    } else
      cnt++;
  }
  cout << cnt << endl;
}