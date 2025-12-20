#include<bits/stdc++.h>
using namespace std;
#define int long long
int main(){
  int q;
  cin>>q;
  queue<int>q;
  int flag=1;
  while (q--) {
    int x;
    cin>>x;
    if(x==1){
      int y;
      cin>>y;
      q.push(y);
      if(y=='(')
      {
        flag=0;
        cout<<"No"<<endl;
        continue;
      }
      else{

      }
    }
    else {
      q.pop();
    }
  }
}
