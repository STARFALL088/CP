#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long lli;
typedef long double lld;
const lli mod = 1e9 + 7;
const lli MAXN = 1e6+1;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define rev(x) reverse(all(x))
#define srt(x) sort(all(x))
#define pb push_back
#define F first
#define S second
#define sq(x) ((x) * (x))
#define setpre(n) fixed << setprecision(n)
#define vi vector<int>
#define vc vector<char>
#define vs vector<string>
#define vll vector<lli>
#define vb vector<bool>
#define pi acos(-1.0)/180.0
#define vec2d(name,n,m,val) vector<vector<int>>(name)((n),vector<int>((m),(val)))
#define tc    \
    int t;    \
    cin >> t; \
    for (int i = 1; i <= t; ++i)
#define tc0   \
    int t = 1; \
    for (int i = 1; i <= t; ++i)
#define nl cout << "\n";
#define case(i) cout << "Case " << i << ": ";
#define input(x) for(auto &i:x) cin>>i
#define print(x) for(auto &i:x) cout<<i<<" ";

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
inline int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
#define lcm(a,b)    (a*b)/gcd(a,b)
string ny[2] = {"no", "yes"};

// *****************************************************
// ------------------- CODE STARTS HERE ----------------
// *****************************************************
bool pc(string s) {
    string temp=s;
    rev(temp);
    return s==temp;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    tc{
        string s;
        cin>>s;
        lli n=s.size();

        string temp2=s;
        rev(temp2);
        if(s!=temp2) {
            cout << "YES" << endl;
            cout << "1" << endl;
            cout << s<< endl;
            continue;
        }

        //a->no
        if(s.size()==1) {
            cout << "NO" << endl;
            continue;
        }
        //aaaaaaa --> no
        //aaabaaa-->no>>>?????
        string temp=s;
        //srt(temp);
        bool o1=1;
        for(int i=0; i<n/2; i++) {
            if(temp[0]!=temp[i]) o1=0;
            //  cout << temp[i]<<" " <<temp[n-i-1]<< endl;
        }
        rev(temp);
        if(o1) {
            cout << "NO" << endl;
            continue;
        }

        //ababa--> no (size->odd ,2 letter, 1 gap)
        bool o2=1;
        if(n&1) {
            for(int i=0; i<n; i+=2) {
                if(s[0]!=s[i]) o2=0;
            }
            for(int i=1; i<n; i+=2) {
                if(s[1]!=s[i]) o2=0;
            }
        }
        else o2=0;
        if(o2) {
            cout << "NO" << endl;
            continue;
        }
        //abaaba--> ab aaba


        //aabaabaa--> aaba abaa

        //s1||s2 --> palindrome.  then s1+1, s2-1

        bool o3=0;
        for (int i = 1; i < n; i++) {
            if (s[i] != s[i - 1]) {
                cout << "YES" << endl;
                cout << "2" << endl;
                if(pc(s.substr(0,i+1))||pc(s.substr(i+1))){
                cout << s.substr(0,i+2)<<" "<<s.substr(i+2) << endl;
                }
                else cout << s.substr(0, i+1) << " " << s.substr(i+1) << endl;
                o3= 1;
                break;
            }
        }
    }
}