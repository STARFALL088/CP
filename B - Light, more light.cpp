#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    while(cin>>n and n!=0){
        if(long(ceil(sqrt(n)))==long(floor(sqrt(n))))cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
}
