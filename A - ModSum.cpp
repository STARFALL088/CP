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
     int n;
     n=ii;
     int sum=0;
     vector<int>p;
     vector<int>store;
     int mx=0;
     for(int i=1;i<=n;i++){
        p.push_back(i);
     }
     while(next_permutation(all(p))){
         int cur=0;
         for(int i=0;i<n;i++){
             cur+=p[i]%i;
         }
         if(cur>sum){
             sum=cur;
             store=p;
         }
     }
     for(auto i:p){
         cout<<i<<" ";
     }
     cout<<endl;
    }
}
