#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7; //998244353; 
#define all(x)(x).begin(), (x).end()
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    for (int ii = 1; ii <= t; ii++) {
        int n;
        cin >> n;
        vector < int > p(n);
        for (auto & i: p) {
            cin >> i;
        }
        set < int > s;
        int cnt = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s.count(p[i])) {
                s.clear();
                s.insert(p[i]);
                cnt++;
            }
            else s.insert(p[i]);
        }
        cout<<cnt<<endl;
    }

}
