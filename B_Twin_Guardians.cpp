#include <bits/stdc++.h>
using namespace std;
#define int long long
  vector<bool> primes(1000010, 1);

void action() {

  int a, b;
  cin >> a >> b;
  if (primes[a] and primes[b] and abs(a - b) == 2)
    cout << "Y" << endl;
  else
    cout << "N" << endl;
}
signed main() {
  primes[0] = primes[1] = 0;
  for (int i = 2; i * i <= 1000002; i++) {
    if (primes[i] == 1) {
      for (int j = i * i; j <= 1000002; j += i) {
        primes[j] = 0;
      }
    }
  }
  int t;
  cin >> t;
  for (int _ = 1; _ <= t; _++)
    action();
}