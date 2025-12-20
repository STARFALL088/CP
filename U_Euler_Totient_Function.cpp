#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
namespace std{
using namespace __gnu_pbds;
template<typename T>
using ordered_set   =   tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
};

#ifndef ONLINE_JUDGE
#include "debug.hpp"
#else
#define debug(x)
#define error(...)
#endif
#define int long long
const int mod = 1e9 + 7; //998244353; 
#define all(x) (x).begin(), (x).end()
int phi(int n) {
    int result = n;
    for (int p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            while (n % p == 0) n /= p;
            result -= result / p;
        }
    }

    if (n > 1) {
        result -= result / n;
    }

    return result;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t=1;
    cin>>t;
    for(int ii=1;ii<=t;ii++){
      int n;
      cin>>n;
      cout<<phi(n)<<endl;
    }
}


map<lli, lli> prime_factorize(lli n) {
    map<lli, lli> factors;
    for (lli i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            factors[i]++;
            n /= i;
        }
    }
    if (n > 1) factors[n]++;
    return factors;
}