

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
    string a, b;
    cin >> a >> b;
    string ans;
    int c = 0;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    while (a.size() < b.size()) a += '0';
    while (b.size() < a.size()) b += '0';
    for (int i = 0; i < a.size(); ++i) {
        int d1 = a[i] - '0';
        int d2 = b[i] - '0';
        int add = d1 + d2 + c;
        c= add / 10;
        ans.push_back(add % 10 + '0');
    }
    if (c)  ans.push_back(c+ '0');
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}
