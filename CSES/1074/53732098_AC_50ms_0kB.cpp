#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long lli;
const long long int MAXN = 1e6 + 1;
const long long mod = 1e9 + 7;

// *****************************************************
// ------------------- CODE STARTS HERE ----------------
// *****************************************************
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int size;
    cin>>size;
    vector<lli>p(size);
    // na hoile baad; khudha lagse @_@
    for(int i=0; i<size; i++)cin>>p[i];
    sort(p.begin(),p.end());
    int mid=p[size/2];
    lli sum=0;
    for(int i=0; i<size; i++) sum+=abs(p[i]-mid);
    cout << sum << endl;
}
