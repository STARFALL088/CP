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
    int n,m,k;
    cin>>n>>m>>k;
    vector<int>p(n);
    vector<int>q(m);
    for(int i=0; i<n; i++) cin>>p[i];
    for(int i=0; i<m; i++) cin>>q[i];
    sort(p.begin(),p.end());
    sort(q.begin(),q.end());
    // 2 pointer
    int i=0,j=0;
    int cnt=0;
    while(i<n&&j<m) {
        if(abs(p[i]-q[j])<=k) {
            i++;
            j++;
            cnt++;
        }
        else if(p[i]>q[j]) {
            j++;
        }
        else i++;
    }
    cout << cnt<< endl;

}