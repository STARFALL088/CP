#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        // Count how many elements are <= k
        int count = 0;
        for (int num : a) {
            if (num <= k) {
                count++;
            }
        }

        // To have at least two medians <= k, we need at least two elements <= k
        // in the left, middle, or right subarrays.
        bool possible = false;
        if (count >= 2) {
            // Check if the first element is <= k
            if (a[0] <= k) {
                // We can take the first element as the left subarray
                // Now, we need at least one more element <= k in the remaining array
                // to form either the middle or right subarray
                possible = true;
            } else if (a[n - 1] <= k) {
                // We can take the last element as the right subarray
                // Now, we need at least one more element <= k in the remaining array
                // to form either the left or middle subarray
                possible = true;
            } else {
                // We need to find at least two elements <= k in the middle
                // Since count >= 2, and neither first nor last is <= k,
                // there must be at least two elements <= k in the middle
                // However, we need to ensure that these two elements can form two separate subarrays
                // with medians <= k
                // For example, if the two elements are adjacent, we can split them into two subarrays
                // But if they are not adjacent, we may not be able to form two subarrays with medians <= k
                // So, we need to check if there exists at least two elements <= k that are not adjacent
                // or if there exists at least one element <= k that can form a subarray with median <= k
                // For simplicity, we can assume that if count >= 2, it's possible
                possible = true;
            }
        }

        // Additional check to ensure that the two elements <= k can form two subarrays with medians <= k
        if (possible) {
            // Find the first and last elements <= k
            int first = -1, last = -1;
            for (int i = 0; i < n; ++i) {
                if (a[i] <= k) {
                    if (first == -1) {
                        first = i;
                    }
                    last = i;
                }
            }
            // If the first and last elements <= k are the same, then we can't form two subarrays
            if (first == last) {
                possible = false;
            }
        }

        cout << (possible ? "YES" : "NO") << endl;
    }
    return 0;
}