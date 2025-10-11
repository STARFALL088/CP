#include<bits/stdc++.h>
using namespace std ;
using lli =long long;
using vll =vector<lli>;

void action(){
  lli n,k,m;
  cin>>n>>k>>m;
  vll p(n),q(n),ase(m+k);
  
  for (int i = 0; i < n; i++)cin>>p[i];
  for (int i = 0; i < n; i++)cin>>q[i];
  priority_queue<lli>z;
  for (int i = 0; i < n; i++)if(p[i]-q[i])z.push(p[i]-q[i]);
  for (int i = 0; i < m+k; i++) {
    cin>>ase[i];
  }   
  sort(ase.rbegin(),ase.rend());
  lli ans=0;
  
  for(auto i:ase){
    
    if(i>z.top())continue;
    lli cur=z.top();
    //cout<<z.top()<<endl;
    z.pop();
    ans+=(cur-i);
  }
  while (!z.empty()) {
    ans+=z.top();
    //cout<<z.top()<<endl;
    z.pop();
  }
  cout<<ans<<endl;
}
int main(){
  int t;
  cin>>t;
  while(t--)action();
}
