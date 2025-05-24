
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long long lli;

typedef vector<lli> vll;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rev(x) reverse(all(x))
#define srt(x) sort(all(x))

#define take(p, n, T) \
    vector<T> p(n);   \
    for (auto &i : p) \
        cin >> i;

#define case(ii) cout << "Case " << ii << ": "
// Loop macros
#define loop(i, n) for (int i = 0; i < (n); ++i)


#define tc    \
    int t;    \
    cin >> t; \
    for (int ii = 1; ii <= t; ++ii)

// *****************************************************
// ------------------- CODE STARTS HERE ----------------
// *****************************************************

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    tc
    {
        lli n;
        cin >> n;
        take(w, n, lli);
        take(b, n, lli);
        lli ans=0;
        loop(i,n){
            ans^=(b[i]-w[i]-1);
        }
       
        case(ii);
        if(ans==0)cout<<"black wins"<<endl;
        else cout<<"white wins"<<endl;
    }
}