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
void action(){
     int n;
     cin>>n;

     int team1=0,team2=0;
     for(int i=0;i<n;i++){

     int type,a,b;
     cin>>type>>a>>b;
     if(type==1){
         cout<<"YES"<<endl;
         team1=a;team2=b;
         
     }
     else{
         if(a==b){
             cout<<"YES"<<endl;
             team1=a,team2=b;
             continue ;
         }
         if(team1>min(a,b)){
             cout<<"YES"<<endl;
             team1=max(a,b);
             team2=min(a,b);
             continue;
         }
         error(a,b,team1);
         cout<<"NO"<<endl;
     }
     }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t=1;
    cin>>t;
    for(int ii=1;ii<=t;ii++){
        action(); 
     
    }
}
