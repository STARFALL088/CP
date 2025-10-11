#include<bits/stdc++.h>
using namespace std;
using lli =long long;
int main (int argc, char *argv[]) {
  int t;
  cin>>t;
  for(int i=0;i<t;i++){
  lli n,k;
  cin>>n>>k;
  string s;
  cin>>s;
  for(auto& i:s){
    for(char j='a';j<='z';j++){
      if(i-j<=k or 26-(i-j)<=k){
        if(i-j<26-i+j){
          k-=(i-j); 
        }
        else{
          k-=(26-i+j);
        }
        i=j;
        break;
      }
    }
  }
  if(k>0 and k%2)s.back()++;
  cout<<s<<endl;
  }
  return 0;
}
