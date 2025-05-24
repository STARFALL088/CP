#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool canPartition(const vector<ll>& a, int n, int m, ll v, ll aliceTastiness) {
    int pieces = 0;
    ll currentSum = 0;

    for (int i = 0; i < n; ++i) {
        currentSum += a[i];

        // Form a new piece if currentSum meets the minimum requirement
        if (currentSum >= v) {
            pieces++;
            currentSum = 0; // Reset for the next piece
        }

        // If we have m valid pieces and the remaining sum is enough for Alice, we’re good
        if (pieces == m) {
            // Calculate the sum of remaining elements
            ll remainingSum = accumulate(a.begin() + i + 1, a.end(), 0LL);
            return remainingSum >= aliceTastiness;
        }
    }
    return false;
}

ll maxAliceTastiness(const vector<ll>& a, int m, ll v) {
    ll totalSum = accumulate(a.begin(), a.end(), 0LL);
    ll left = 0, right = totalSum, result = -1;

    // Binary search on Alice's maximum possible tastiness
    while (left <= right) {
        ll mid = left + (right - left) / 2;

        if (canPartition(a, a.size(), m, v, mid)) {
            result = mid; // mid is feasible, try for a larger tastiness
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        ll v;
        cin >> n >> m >> v;
        vector<ll> a(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        ll result = maxAliceTastiness(a, m, v);
        cout << result << '\n';
    }

    return 0;
}
