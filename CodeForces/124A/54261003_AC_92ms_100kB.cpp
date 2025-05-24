#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long lli;
// *****************************************************
// ------------------- CODE STARTS HERE ----------------
// *****************************************************


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,a,b;
    cin>>n>>a>>b;
    int front=0;
    int back=n-1;
    int cnt=0;
    for(int i=1; i<=n; i++) {
        // front --> min a
        //back --> max b

        if(front>=a && back<=b) {
            cnt++;
        }
        front++;
        back--;
    }
    cout << cnt<< endl;
}