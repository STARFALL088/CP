#include <bits/stdc++.h>
using namespace std;
using lli = long long;
using vll = vector<lli>;
lli MAXN = 1e6 + 9;
class DSU {
  vll rank, parent;

public:
  DSU(lli n) {
    rank.resize(n + 1, 0);
    parent.resize(n + 1, 0);
    for (lli i = 0; i <= n; i++)
      parent[i] = i;
  }
  lli find(lli node) {
    if (node == parent[node])
      return node;
    return parent[node] = find(parent[node]);
  }
  void uniomSets(lli u, lli v) {
    lli rootU = find(u);
    lli rootV = find(v);
    if (rootU == rootV)
      return;
    if (rank[rootU] < rank[rootV])
      parent[rootU] = rootV;
    else if (rank[rootU] > rank[rootV])
      parent[rootV] = rootU;
    else {
      parent[rootV] = rootU;
      rank[rootU]++;
    }
  }
  lli sz() {
    lli cnt = 0;
    map<lli, lli> m;
    for (auto i : parent)
      m[i]++;
    for (auto [i, j] : m)
      cerr << i << " " << j << endl;
    return m.size();
  }
};
int main(){
    lli m;
    cin>>m;
    DSU p(m);
    map<pair<lli,lli>,lli>mp;
    vector<pair<lli,lli>>q;
    for(int i=1;i<=m;i++){
        lli x;
        cin>>x;
        for(int ii=0;ii<x;ii++){
            lli z;
            cin>>z;
            q.push_back({i,z});
            mp[{i,z}]++;
        }
    }

    for(auto [u,v]:q){
        if(mp.count({u,v}) and mp.count({v,u}))p.uniomSets(u, v);
    }

    




}