#include <bits/stdc++.h>
using namespace std;

#ifdef SMIE
#define debug(x) cerr << #x << " = " << (x) << endl
#endif

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<bitset<10>(i)<<endl;
    }
    return 0;
}
