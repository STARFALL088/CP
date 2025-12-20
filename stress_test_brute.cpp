#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    if(n > 50) cout << n * 2 + 1 << endl;  // Wrong for n > 50
    else cout << n * 2 << endl;
    return 0;
}
