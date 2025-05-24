#include <bits/stdc++.h>
using namespace std;

int main() {
    int tests;
    cin >> tests;
    while (tests--) {
        int n;
        string s;
        cin >> n >> s;
        
        
        int tot = 0;
        int cng1 = 0, cng2 = 0;
        
        if (n > 0 && s[0] == '1' ) {
            tot++;
            cng1++;
        }
        for (int i = 1; i < n; i++) {
            if (s[i] != s[i-1]) {
                tot++;
                if (s[i-1] == '0' && s[i] == '1') cng1++;
                else if (s[i-1] == '1' && s[i] == '0') cng2++;
            }
        }
        int ans = n + tot;
        int reduction = (cng1 >= 1 && cng2 >= 1) ? 2 : 0;
        if(cng2 and cng1==0)ans++;
        cout << ans - reduction << endl;
    }
    return 0;
}