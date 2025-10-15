#include <bits/stdc++.h>
// #include <climits>
using namespace std;
#define ll long long

int main() {

  ll x;
  cin >> x;

  ll arr[x][x];
  for (ll i = 0; i < x; i++) {

    for (ll j = 0; j < x; j++) {

      cin >> arr[i][j];
    }
  }
  ll count = 0;
  vector<ll> row(x, 0);
  vector<ll> col(x, 0);

  for (ll i = 0; i < x; i++) {

    for (ll j = 0; j < x; j++) {

      if (arr[i][j] < 1) {
        row[i]++;
        col[j]++;
        count++;
      }
    }
  }

  // for ()

  ll q = 0;
  for (ll i = 0; i < x; i++) {

    for (ll j = 0; j < x; j++) {

      if (arr[i][j] > 1) {

        if (row[i] == 0 && col[j] == 0) {
          continue;
        } else if (row[i] > col[j]) {
          ll x = min(arr[i][j] - 1, row[i]);
          row[i] -= x;
          ll y = min(arr[i][j] - 1, col[j]);
          col[j] -= y;
          q += x + y;

        } else {
          ll y = min(arr[i][j] - 1, col[j]);
          col[j] -= y;
          ll x = min(arr[i][j] - 1, row[i]);
          row[i] -= x;
          q += (x + y);
        }
      }
    }
  }

  ll sum = q + (count - q) * 2;
  cout << sum << endl;

  return 0;
}