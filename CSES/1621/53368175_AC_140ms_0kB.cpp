#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long lli;
const long long int MAXN = 1e6+ 1;
// *****************************************************
// ------------------- CODE STARTS HERE ----------------
// *****************************************************

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int size;
    cin>>size;
    set<int>s;
    for(int i=0; i<size; i++) {
        int a;
        cin>>a;
        s.insert(a);
    }
    cout << s.size()<< endl;
}