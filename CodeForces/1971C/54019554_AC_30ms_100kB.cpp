#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        int size=abs(a-b)+1;
        int p[size];
        a=min(a,b);
        b=max(a,b);
        bool isPossible=0;
        for(int i=0; i<size; i++) {
            p[i]=a;
            a++;
        //    cout << p[i] ;
        }
        //cout << "" << endl;
        for(int i=0; i<size; i++) {
            if(p[i]==c) isPossible=!isPossible;
            if(p[i]==d) isPossible=!isPossible;
        }
        if(isPossible) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}