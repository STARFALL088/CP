#include <bits/stdc++.h>
using namespace std;
typedef long long lli;
const int MAXN = 1e6 + 1;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // list of prime
    vector<bool> prime(MAXN, true);
    prime[0] = prime[1] = false; 
    for (int i = 2; i * i <= MAXN; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= MAXN; j += i) {
                prime[j] = false;
            }
        }
    }

    vector<int> a;
    for (int i = 2; i <= MAXN; i++) {
        if (prime[i]) a.push_back(i);
    }

    int t;
    cin >> t;
    while (t--) {
        int d;
        cin >> d;

        // first find
        int p = d;
        auto it = upper_bound(a.begin(), a.end(), p);
        if (it != a.end()) p = *it;
        int prod = p;
        // second find
        it = upper_bound(a.begin(), a.end(), p + d-1);
        if (it != a.end()) p = *it;
        prod *= p;
        cout << prod << endl;
    }
    return 0;
}