#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long lli;
const long long int MAXN = 1e7 + 1;
const long long mod = 1e9 + 7;

// *****************************************************
// ------------------- CODE STARTS HERE ----------------
// *****************************************************
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // toph er question -_-
    // aj login ney na bole aabar lekha laglo
    int n;
    cin>>n;
    cin.ignore(); // faltu line
    int a;
    string s;
    getline(cin,s);
    for(int i=0; i<s.size(); i++) {
        if(s[i]==' ') continue;
        a=s[i]-n;
        if(a<97) a+=26;
        s[i]=a;
    }
    cout << s << endl;
}
