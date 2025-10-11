#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
using namespace std;
#define int long long
signed main() {
    int n;
    cin>>n;
    vector<double>p(n);
    for(auto &i:p)cin>>i;
    sort(p.begin(),p.end());
    
    double z=(p[0]+p.back())/2.0;
    cerr<<z<<endl;
    double diff=INT_MAX;
    double mn=INT_MAX;
    for(auto ele:p){
        double cur=abs(z-(double)ele);
        if(cur<diff){
            mn=ele;
            diff=cur;
        }
    }
    cout<<mn;
}