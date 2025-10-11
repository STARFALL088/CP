#include<bits/stdc++.h>
using namespace std;
using lli =long long;
void action(){
  lli n,c;
  cin>>n>>c;
  lli last=0,cnt=0;
  for(int i=0;i<n;i++){
    lli x;
    cin>>x;
    if(x-last>=c){
      last=x;
      cnt++;
    }
  }
  cout<<cnt<<endl;
}
int main (int argc, char *argv[]) {
  int t=1;
  //cin>>t;
  action();
  return 0;
}