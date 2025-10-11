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