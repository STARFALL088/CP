#include <bits/stdc++.h>
#include <queue>
using namespace std;
using lli = long long;
void action() {
  lli n, c;
  cin >> n >> c;
  vector<lli> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  priority_queue<lli, vector<lli>, greater<lli>> z;
  for (int i = 0; i < c; i++)
    z.push(p[i]);
  cout << z.top() << endl;
  for (int i = c; i < n; i++) {

    if (p[i] > z.top()) {
      z.pop();
      z.push(p[i]);
    }
    cout << z.top() << endl;
  }
}
int main(int argc, char *argv[]) {
  int t = 1;
  // cin>>t;
  action();
  return 0;
}