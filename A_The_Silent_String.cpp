#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    int a, b, cnt = 0;
    cin >> a >> b >> s;
    int l=lcm<int>(a,b);
    cerr<<l<<endl;

    for (auto i : s) {
      if (!(i != 'a' and i != 'e' and i != 'i' and i != 'o' and i != 'u'))
        cnt += b;
    }
    cout << cnt << endl;
  }

  return 0;
}
