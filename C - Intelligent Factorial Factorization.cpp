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
vector<vector<int>>p(101,vector<int>(101,0));
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int MAXN=101;
    vector<bool> primes(MAXN+1, 1);
    primes[0] = primes[1] = 0;
    for (int i = 2; i * i <= MAXN; i++) {
          if (primes[i] == 1) {
            for (int j = i * i; j <= MAXN; j += i) {
                  primes[j] = 0;
            }
        }
    }
    vector<int>prime;
    vector<int>mx(101,0);
    for (int i = 0; i <= MAXN; i++) if (primes[i]) prime.push_back(i);
    for(int i=2;i<=100;i++){
        p[i]=p[i-1];
        mx[i]=mx[i-1];
        int cur=i;
        for(auto ele:prime){
            while(cur%ele==0){
                p[i][ele]++;
                mx[i]=max(ele,mx[i]);
                cur/=ele;
            }
        }
        if(cur!=1){
            mx[i]=max(cur,mx[i]);
            p[i][cur]++;
        }

    }
    int t=1;
    cin>>t;
    for(int ii=1;ii<=t;ii++){
      int n;
      cin>>n;
      cout<<"Case "<<ii<<": "<<n<<" = ";
      for(int i=2;i<101;i++){
          if(primes[i] and p[n][i]){
            cout<<i<<" ("<<p[n][i]<<")"<<((i==mx[n])?"":" * ");
          }
      }
      cout<<endl;
    }
}
