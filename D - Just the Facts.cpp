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
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>p(10010,1LL);
    for(int i=1;i<10003;i++){
        int cur=p[i-1]*i;
        while(cur%10==0)cur/=10;
        p[i]=cur%10;
    }
    int n;
    while(cin>>n){
        cout<<string(long(5-log10(n)),' ')<<n<<" -> "<<p[n]<<endl;
    }
}
