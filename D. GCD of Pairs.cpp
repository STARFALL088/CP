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
    int MAXN=1000001;
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
    for(int i=0;i<MAXN;i++)if(primes[i])prime.push_back(i);
    int t=1;
    cin>>t;
    for(int ii=1;ii<=t;ii++){
     int n;
     cin>>n;
     int cnt=0;
     vector<int>p(n),q(n);
     for(auto &i:p)cin>>i;
     for(auto &i:q)cin>>i;
     sort(all(p));
     sort(all(q));
     /*
     for(int i=0;i<n;i++){
         for(int j=0;j<n;j++){
             if(primes[gcd<int>(p[i],q[j])])cnt++;
         }
     }*/
     map<int,pair<int,int>>m;
     for(int i=0;i<n;i++){
        for(auto ele:prime){
            if(ele*ele>n)break;
            if(p[i]%ele==0){
                m[ele].first++;
                while(p[i]%ele==0)p[i]/=ele;
            }
        }
        if(p[i]>1)m[p[i]].first++;
        for(auto ele:prime){
            if(ele*ele>n)break;
            if(q[i]%ele==0){
                m[ele].second++;
                while(q[i]%ele==0)q[i]/=ele;
            }
        }
        if(q[i]>1)m[q[i]].second++;
     }
     //for(auto [ele,val]:m)cnt+=val.first*val.second;
     /*
        for(auto i:prime){
         if(m.count(i)){
             cnt+=m[i].first*m[i].second;
        }
     }*/
     for(int i=0;i<n;i++){
         if()
     }
     cout<<cnt<<endl;
    }
}
