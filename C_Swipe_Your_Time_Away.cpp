#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
  int t;
  cin >> t;
  for (int _ = 1; _ <= t; _++) {
    cout << "Case " << _ << ": ";

    int n, m;
    cin >> n >> m;
    int p[n + 2][m + 2];
    memset(p, 0, sizeof(p));
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cin >> p[i][j];
      }
    }

    int left[n + 2][m + 2];
    memset(left, 0, sizeof(left));
    for (int i = 1; i <= n; i++) {
      left[i][1] = 1;
      for (int j = 2; j <= m; j++) {
        if (p[i][j - 1] == p[i][j])
          left[i][j] = left[i][j - 1] + 1;
        else
          left[i][j] = 1;
      }
    }

    int right[n + 2][m + 2];
    memset(right, 0, sizeof(right));
    for (int i = 1; i <= n; i++) {
      right[i][m] = 1;
      for (int j = m - 1; j >= 1; j--) {
        if (p[i][j + 1] == p[i][j])
          right[i][j] = right[i][j + 1] + 1;
        else
          right[i][j] = 1;
      }
    }

    int up[n + 2][m + 2];
    memset(up, 0, sizeof(up));
    for (int j = 1; j <= m; j++) {
      // left[i][0]=1;
      up[1][j] = 1;
      for (int i = 2; i <= n; i++) {
        if (p[i - 1][j] == p[i][j])
          up[i][j] = up[i - 1][j] + 1;
        else
          up[i][j] = 1;
      }
    }

    int down[n + 2][m + 2];
    memset(down, 0, sizeof(down));
    for (int j = 1; j <= m; j++) {
      // left[i][0]=1;
      down[n][j] = 1;
      for (int i = n - 1; i >= 1; i--) {
        if (p[i + 1][j] == p[i][j])
          down[i][j] = down[i + 1][j] + 1;
        else
          down[i][j] = 1;
      }
    }
    int mx = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        // cout<<" "<<left[i][j]<<right[i][j]<<up[i][j]<<down[i][j]<<" ";
        if (left[i][j] > 1 and right[i][j] > 1 and up[i][j] > 1 and
            down[i][j] > 1) {
          mx = max(mx, left[i][j] + right[i][j] + up[i][j] + down[i][j] - 3);
        }
      }
    //   cout<<endl;
    }
    cout << mx << endl;
  }
}