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
        int size,mod;
        cin >> size>>mod;
        vector<int> p(size);
        for (int i = 0; i < size; i++) {
            cin >> p[i];
            p[i] %= mod;
            //ebar line e line e mod marbo --_-
        }
        string s;
        cin >> s;
        int l = 0, r = size-1;
        vector<int>index(size);
        for(int i = 0; i < size; i++) {
            if(s[i] == 'L') {
                index[i] = l++;
            } else {
                index[i] = r--;
            }
        }
        vector<int>ans(size);
        lli temp= 1;
        for(int i = size-1; i >= 0; i--) {
            temp *= p[index[i]];
            temp %= mod;
            
            ans[i] = temp;
        }
        for(int i = 0; i < size; i++)
            cout << ans[i]%mod << " ";
        cout << endl;
        
    }
}