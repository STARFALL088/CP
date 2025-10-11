#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    cout<<a<<" "<<b<<" "<<c<<endl;
    int cnt = (a>=10) + (b>=10) + (c>=10);
    if (cnt == 0)
      cout << "zilch" << endl;
    else if (cnt == 1)
      cout << "double" << endl;
    else if (cnt == 2)
      cout << "double-double" << endl;
    else if (cnt == 3)
      cout << "triple-double" << endl;
    
  }
}