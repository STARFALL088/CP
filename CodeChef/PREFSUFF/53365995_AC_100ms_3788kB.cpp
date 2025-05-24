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
// hoile hoibo ,na hoile nai. -_-
    int t;
    cin>>t;
    while(t--) {
        int size;
        cin>>size;
        vector<int>p(size,5);
        p[size-1]=1;
        for(int i=0; i<size; i++) cout << p[i]<<" " ;
        cout << "" << endl;
    }
}