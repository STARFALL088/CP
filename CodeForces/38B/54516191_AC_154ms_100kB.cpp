#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long lli;
typedef long double lld;
const lli mod = 1e9 + 7;
const lli MAXN = 10e6;
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
#define pi acos(-1.0)
#define vec2d(name, n, m, val) vector<vector<int>> name((n), vector<int>((m), (val)))
#define tc    \
    int t;    \
    cin >> t; \
    for (int ii = 1; ii <= t; ++ii)
#define tc0    \
    int t = 1; \
    for (int ii = 1; ii <= t; ++ii)
#define nl cout << "\n";
#define case(ii) cout << "Case " << ii << ": ";
#define input(x) for (auto &i : x) cin >> i
#define print(x) for (auto &i : x) cout << i << " ";
#define arrsum(arr) std::accumulate(arr.begin(), arr.end(), 0LL)


constexpr int dx[] = {0, 0, 1, -1};
constexpr int dy[] = {1, -1, 0, 0};

inline int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

#define lcm(a, b) ((a) * (b)) / gcd(a, b)
const string ny[] = {"NO", "YES"};

// *****************************************************
// ------------------- CODE STARTS HERE ----------------
// *****************************************************

void knight(vector<vector<int>>& p, int x, int y) {
    // Define the knight's possible moves (8 directions)
    int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
    int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};

    // Mark the current position
    p[x][y] = 1;

    // Loop through all possible knight moves
    for (int i = 0; i < 8; ++i) {
        int nx = x + dx[i];  // New x position
        int ny = y + dy[i];  // New y position

        // Check if the new position is valid (inside the 8x8 board)
        if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8) {
            p[nx][ny] = 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<vector<int>>p(8,vector<int>(8,0));
    string a,b;
    cin>>a>>b;
    int x=(int)(a[0]-'a');
    int y=(int)(a[1]-'0');
    y--;
    //marks ♖ 
    for(int i=0; i<8; i++) {
        p[x][i]=1;
        p[i][y]=1;
    }
    //mark the position from where new ♘ can attack the ♖ 
    knight(p,x,y);
    int x1=(int)(b[0]-'a');
    int y1=(int)(b[1]-'0');
    y1--;
    //mark ♞ 
    knight(p,x1,y1);
    int cnt=0;
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            //  cout<<p[i][j]<<" ";
            cnt+=p[i][j];
        }
        ///  cout << "" << endl;
    }
    cout<<64-cnt<<endl;

}