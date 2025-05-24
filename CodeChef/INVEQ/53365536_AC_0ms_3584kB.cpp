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
    int t;
    cin>>t;
    while(t--) {
        int size;
        cin>>size;
        string s;
        cin>>s;
        int cnt=1;
        for(int i=0; i<size-1; i++)if(s[i]!=s[i+1]) cnt++;
        
        cout << cnt/2<< endl;
    }
}