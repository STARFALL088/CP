#include <bits/stdc++.h>
using namespace std;
using lli = long long;
bool action() {
  lli s, t, x;
  cin >> s >> t >> x;
  if (t < s)
    t += 24;
  if (x < s)
    x += 24;
  if (x < t and x >= s) {
    return 1;
  }
  return 0;
}
int main(int argc, char *argv[]) {
  int t = 1;
  // cin>>t;
  cout << (action() ? "Yes" : "No");
  return 0;
}