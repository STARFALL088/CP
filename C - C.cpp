#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
namespace std{
using namespace __gnu_pbds;
template<typename T>
using ordered_set   =   tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
};
#define dup(x,y) ((x)+(y)-1)/(y)
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
    //cin>>t;
    for(int ii=1;ii<=t;ii++){
      int n,k;
      cin>>n>>k;
      vector<int>p(n);
      for(auto &i:p)cin>>i;
      int pos=-1;
      for(int i=0;i<n;i++){
          if(p[i]==1)pos=i+1;
      }
      
      int ans=dup(pos-1,k-1);
      if((pos)%k!=0){
        pos=dup(pos,k-1)*k+1;
      }
      cout<<dup(n-pos-1,k-1)+ans;
    }
}
