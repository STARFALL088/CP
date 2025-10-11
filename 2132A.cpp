#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  while (t--) {
    int x,y;
    string a,b;
    cin>>x>>a>>y>>b;
    deque<char>p=a;
    for(int i=0;i<b;i++){
      char z;
      cin>>z;
      if(z=='D')p.push_back(z);
      else {
        p.push_front(z);
      }
    for(auto i:p)cout<<i;
    cout<<endl;

  }
}
