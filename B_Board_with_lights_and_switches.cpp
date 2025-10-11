#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

 int n;
 cin>>n;
 if(n<5)return cout<<-1,0;
 else{
    int cnt=n;
    int move=0;
    while(1){
        int x=cnt/2;
        int y=cnt-cnt/2;
        move++;
        cnt=x*y;
        if(cnt>=1000000000LL)return cout<<move,0;
    }
 }
  
}