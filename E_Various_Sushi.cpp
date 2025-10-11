#include <bits/stdc++.h>
using namespace std;
using lli = long long;
using vll=vector<lli>;
lli MAXN = 1e6 + 669;

class DSU
{
    vll rank, parent;

public:
    DSU(lli n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (lli i = 0; i <= n; ++i)
        {
            parent[i] = i;
        }
    }

    lli find(lli node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = find(parent[node]); // Path compression
    }

    void unionSets(lli u, lli v)
    {
        lli rootU = find(u);
        lli rootV = find(v);

        if (rootU == rootV)
        {
            return; // Both elements are already in the same set
        }

        // Union by rank
        if (rank[rootU] < rank[rootV])
        {
            parent[rootU] = rootV;
        }
        else if (rank[rootV] < rank[rootU])
        {
            parent[rootV] = rootU;
        }
        else
        {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
};
void action() {
 lli n;
 cin>>n;
 //same cycle er element->no
 //d
 DSU p(n);
 for(int i=0;i<n;i++){
    lli x,y;
    cin>>x>>y;
    p.unionSets(x, y);

 }
}
int main(int argc, char *argv[]) {
  int t = 1;
  // cin>>t;
  action();
  // cout << (action() ? "Yes" : "No");
  return 0;
}