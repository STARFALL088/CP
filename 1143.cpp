#include<bits/stdc++.h>
using namespace std;
#define int long long
int f(int x){
  if(x==0)return 1;
  if(x<9)return x;
  return max(9*f(x/10-1),x%10*f(x/10));
}
signed main(){
  int n;
  cin>>n;
  cout<<f(n)<<endl;
}
