#include<bits/stdc++.h>
#include <iomanip>
using namespace std;
using lli =long long;
int main (int argc, char *argv[]) {

  freopen("angle1.in","r",stdin);
  freopen("angle1.out","w",stdout);
  int t=1;
  //cin>>t;
  for(int i=1;i<=t;i++){
    long double x,y;
    cin>>x>>y;
    long double ans=atan2(y,x);
    if(ans<0)ans+=2*acos(-1.0);
    cerr<<ans;
    cout<<fixed<<setprecision(15)<<ans;
  }
  return 0;
}
