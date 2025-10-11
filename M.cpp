#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using lli = long long;
using vll = vector<lli>;
int main() {
  lli n;
  cin >> n;
  lli sum = 0;
  vector<lli> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  sort(p.begin(), p.end());
  for (int i = 30; i >=0; i--) {
    lli cnt = 0, z = -1;
    for (int j = 0; j < n; j++) {
      if ((1LL << i) & p[j]) {
        cnt++;
        if (((1LL << (i + 1))) > p[j])
          z = j;
      }
    }
    // cerr<<cnt<<endl;
    // if (cnt == 0)
    //   continue;
    if(z==-1)continue;
    lli baki = n - cnt;

    if (baki > cnt ) {
      //   lli ii;
      //   for (ii = 0; ii < n; ii++) {
      //     if (p[ii] == 0)
      //       continue;
      //     lli pow = (lli)log2(p[ii]);
      //     cerr<<i<<" " << ii << " " << p[ii] << " " << pow << " " << endl;
      //   }
      //   ii--;
      lli tmp = p[z];
      for (int x = 0; x < n; x++) {
        p[x] ^= tmp;
      }
    }
  }
  for (int i = 0; i < n; i++)
    sum += p[i];
  cout << sum;
}