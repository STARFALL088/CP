#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
  int n;
  cin >> n;
  vector<int> p(n, 0);
  for (auto &i : p)
    cin >> i;
  sort(p.begin(), p.end());
  vector<int> q(n+1, 0);
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    q[i] = (sum += p[i-1]);
  }
  cerr << sum;
  int t;
  cin >> t;
  while (t--) {
    int x;
    cin >> x;
    
      int z = lower_bound(p.begin(), p.end(), x) - p.begin() ;
      int cur = sum - q[z];
      int ase = sum;
      int pore_ase = n - z;
      cerr << pore_ase << endl;
      cur -= pore_ase * x;
      cout <<max( cur,0LL) << endl;
      
    
  }
}