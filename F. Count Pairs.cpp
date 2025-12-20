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

    int t=1;
    cin>>t;
    for(int ii=1;ii<=t;ii++){
     int k;
     cin>>k;
     int cnt=0;
     for(int i=0;i*i<=k;i++){
         for(int j=0;j*j<=k;j++){
             if(i*i+j*j<=k){
                if(i==0 and j==0)cnt++;
                else if(i==0 or j==0)cnt+=2;
                else cnt+=4;
             }
         }
     }
     cout<<cnt<<endl;
    }
}
