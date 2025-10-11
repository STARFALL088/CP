#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  set<int> s;
  int cur = n;
  s.insert(n);
  int itr = 0;
  while (cur != 1) {
    int v = n / cur;
    s.insert(v);
    int nxt = v + 1;
    cur = n / nxt;
    itr++;
  }
  // cerr << itr;
  cout << s.size() << endl;
  for (auto i : s)
    cout << i << " ";
}
