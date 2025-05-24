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
        int n;
        cin>>n;
        if(n==1) cout << "1" << endl;
        else if(n==2) cout << "-1" << endl;
        else {
            int cnt=0;
            for(int i=1; i<=n*n; i++) {
                if(i&1) {
                    cnt++;
                    cout << i <<" ";
                }
                if(cnt%n==0) cout << "" << endl;
            }
            for(int i=1; i<=n*n; i++) {
                if(i%2==0) {
                    cnt++;
                    cout << i <<" ";
                }
                if(cnt%n==0) cout << "" << endl;
            }
        }
    }
}