#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define int long long
string rec(string s) {
  if (s.size() == 1) {
    return s;
  }
  string a, b;
  a = s.substr(0, s.size() / 2);
  b = s.substr(s.size() / 2);
  string a_ = rec(a);
  reverse(a_.begin(), a_.end());
  string b_ = rec(b);
  reverse(b_.begin(), b_.end());

  return a_ + b_;
}
signed main() {
  string s;

  cin >> s;
  //   a=s.substr(0,s.size()/2);
  //   b=s.substr(s.size()/2);
  //   cerr<<a<<" "<<b<<endl;

  reverse(s.begin(), s.end());
  cout << rec(s);
}
