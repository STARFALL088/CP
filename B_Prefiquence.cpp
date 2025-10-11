#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    int k = 0;
    for (int i = 0; i < m; i++) {
      if (a[k] == b[i])
        k++;
    }
    cout << k << endl;
  }
}



void Interact(){
    #undef endl
    std::cout << std::endl;
    std::cout.flush();
    #define endl '\n'
}

ll ask(ll l, ll r){
    std::cout << "? " << l << gp << r;
    Interact();
    ll res; std::cin>>res;
    return res;
}

void Report(std::vector<ll> &perm){
    std::cout << "! ";
    for(auto &pr : perm) std::cout << pr << gp;
    Interact();
}