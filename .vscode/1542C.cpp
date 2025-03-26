#include <bits/stdc++.h>
#include <ranges>  // Include ranges header
using namespace std;

using ll = long long;

int main() {
    int t;
    cin >> t;

    while (t--) {
        ll n, k;
        cin >> n >> k;
        cout << *ranges::partition_point(ranges::views::iota(0ll, ll(1e18)), [&] (ll x) { return x - x/n < k; }) << "\n";
    }
    return 0;
}
