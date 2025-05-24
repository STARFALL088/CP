#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
int main(){
  long long a,b;
  cin>>a>>b;
  cout<<(a/b) + (a%b!=0);
}