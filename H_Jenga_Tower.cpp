#include <bits/stdc++.h>
#include <climits>
#include <unordered_map>
using namespace std;
#define int long long
signed main() {
  int n;
  cin >> n;
  vector<int> p(n), q(n);
  for (int i = 0; i < n; i++)
    cin >> p[i];
  for (int i = 0; i < n; i++)
    cin >> q[i];
  unordered_map<int, int> m;
  for (int i = 0; i < (1 << n); i++) {
    int sum = 0;
    int cnt = n;
    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) {
        sum += p[j];
        cnt--;
      }
    }

    if (m.count(sum))
      m[sum] = min(m[sum], cnt);
    else
      m[sum] = cnt;
  }
  int ans = LLONG_MAX;

  for (int i = 0; i < (1 << n); i++) {
    int sum = 0;
    int cnt = n;
    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) {
        sum += q[j];
        cnt--;
      }
    }

    if (m.count(sum)) {
      ans = min(ans, m[sum] + cnt);
    }
  }

  cout<<ans<<endl;
}