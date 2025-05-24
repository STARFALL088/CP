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
    cin >> size;
    vector<int> m(MAXN,0);
    int flag=1;
    for(int i=1; i<=size; i++) {
        int x;
        cin>>x;
        for(int j=flag; j<x+flag; j++) m[j]=i;
        flag+=x;
    }

    int t;
    cin>>t;
    while(t--) {
        int a;
        cin>>a;
        cout<<m[a]<<endl;
    }
}