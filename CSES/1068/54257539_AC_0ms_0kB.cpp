#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long lli;
const long long int MAXN = 1e6 + 1;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n;
    cin >> n;
    cout<<n<<" ";
    while(n!=1) {
        if(n&1) {
            n=n*3+1;
            cout<<n<<" ";
        }
        else {
            n/=2;
            cout<<n<<" ";
        }
    }
}
