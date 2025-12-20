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
    deque<int>a,b;
    for(int ii=1;ii<=t;ii++){
      string s;
      cin>>s;
      if(s=="back"){
          if(a.empty()==0){
              cout<<a.back()<<endl;
              a.pop_back();
              b.pop_front();
          }
          else{
              cout<<"No job for Ada?"<<endl;
          }
      }
      else if(s=="front"){
        if(a.empty()==0){
              cout<<a.front()<<endl;
              a.pop_front();
              b.pop_back();
          }
          else{
              cout<<"No job for Ada?"<<endl;
          }
      }
      else if(s=="reverse"){
          swap(a,b);
      }
      else if(s=="push_back"){
          int n;
          cin>>n;
          a.push_back(n);
          b.push_front(n);
      }
      else if(s=="toFront"){
          int n;
          cin>>n;
          b.push_back(n);
          a.push_front(n);
      }
    }
}
