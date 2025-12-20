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
int g(int x){
    if(x%2==0)return x/2;
    return g(x/2);
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t=1;
    cin>>t;
    for(int ii=1;ii<=t;ii++){
     cout<<"Case "<<ii<<": ";   
     int n;
     cin>>n;
     int x,ans=0;
     for(int i=0;i<n;i++){
         cin>>x;
         ans^=g(x);
     }
     if(ans){
         cout<<"Alice"<<endl;
     }else{
         cout<<"Bob"<<endl;
     }
    }
}
