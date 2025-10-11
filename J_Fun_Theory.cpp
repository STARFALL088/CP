#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define int long long
signed main() {
  int n;
  cin >> n;
  vector<int> p(n);

  for (auto &i : p)
    cin >> i;

  unordered_map<int, int> m;
  for (auto i : p)
    m[i]++;
  for(auto baki:p){
    int ase=n-baki;
    cerr<<ase<<endl;
    if( m[baki]%ase)return cout<<"Impossible",0;
  }
  return cout<<"Possible",0;
}