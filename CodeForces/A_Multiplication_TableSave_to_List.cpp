#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long lli;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    lli n,a;
    cin>>n>>a;
    lli cnt=0;
    for(lli i=1; i<=n ;i++) if(a%i==0&&a/i<=n) cnt++;
    cout << cnt;
}