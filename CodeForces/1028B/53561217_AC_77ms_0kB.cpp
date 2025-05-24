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
    int a,b;
    cin>>a>>b;
    //m+n<10  c=m+n
    //m+n>=10 c=m+n-10
    
    vector<char>p(300,'4');
    p[299]='5';
    vector<char>q(300,'5');
    for(int i=0;i<300;i++) cout<<p[i];
    cout << "" << endl;
    for(int i=0;i<300;i++) cout<<q[i];
    }