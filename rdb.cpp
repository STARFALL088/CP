#include <bits/stdc++.h>
using namespace std;
#define int long long
#define tt() int t; cin >> t; while(t--)
#define all(a) a.begin(), a.end()
#define pb push_back
#define sz(a) ((int)a.size())
#define F first
#define S second
#define __lcm(a,b) (a*b)/__gcd(a,b)
using vi = vector<int>;
using pii = pair<int, int>; 
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define sp ' '
#define endl '\n'
#define rep1(a,n) for (int i = a; i < (n); ++i)
#define rep2(i,a,b) for(int i = a; i <= b ; ++i)
istream& operator>>(istream& is, vector<int>& v) {
for (auto& element : v) is >> element; return is;}
const int N = 1e7 + 10;
bool prime[N];
void solve() {
    int a,b; cin >> a >> b;
    // if(b>a){
    //     swap(a,b);
    // }
    if(prime[a] && prime[b]){
        yes;
        return;
    }
    else if(prime[a] && !prime[b]){
        for(int i = 2 ; i*i <= b; i++){
            if (b % i == 0) {
                int k = b / i;
                if(prime[i] && prime[k]){
                    yes;
                    return;
                }
            }
        }
    }
    else if(!prime[a] && prime[b]){
        for(int i = 2 ; i*i <= a; i++){
            if (a % i == 0) {
                int k = a / i;
                if(prime[i] && prime[k]){
                    yes;
                    return;
                }
            }
        }
    }
    else if(!prime[a] && !prime[b]){
        bool x = false , y = false;
        for(int i = 2 ; i*i <= b; i++){
            if (b % i == 0) {
                int k = b / i;
                if(prime[i] && prime[k]){
                    x = true;
                    return;
                }
            }
        }
        for(int i = 2 ; i*i <= a; i++){
            if (a % i == 0) {
                int k = a / i;
                if(prime[i] && prime[k]){
                    y = true;
                    return;
                }
            }
        }
        if(x && y){
            yes;
            return;
        }
    }
    no;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fill(prime+2,prime+N,true);
    for(int i = 2 ; i <=N ; i++){
        if(prime[i]){
            for(int j = 2*i ; j <= N ; j+=i){
                prime[j]=false;
            }
        }
    }
    //tt()
    solve();
    return 0;
}