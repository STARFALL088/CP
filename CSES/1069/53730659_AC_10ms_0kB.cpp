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
    string s;
    getline(cin,s);
    // quetion na pore korle ja hoy-_-
    int mx=1;
    int str=1;
    for(int i=1; i<s.size(); i++) {
        if(s[i-1]==s[i]) {
            mx++;
            str=max(mx,str);
        }
        else mx=1;
    }
    cout << str<< endl;
}