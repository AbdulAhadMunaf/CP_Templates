template <int SZ>
struct DSU
{
    int par[SZ], sz[SZ];
    DSU()
    {
        forn(0, SZ)
        {
            par[i] = i,
            sz[i] = 1;
        }
    }

    int get(int x)
    { // path compression
        if (par[x] != x)
            par[x] = get(par[x]);
        return par[x];
    }

    bool unite(int x, int y)
    { // union-by-rank
        x = get(x), y = get(y);
        if (x == y)
            return 0;
        if (sz[x] < sz[y])
            swap(x, y);
        sz[x] += sz[y], par[y] = x;
        return 1;
    }
};

// const int MAX_N = 1e5 + 1;
// vi parent(MAX_N), sz(MAX_N);

// int find_set(int v)
// {
//     if (v == parent[v])
//         return v;
//     return parent[v] = find_set(parent[v]);
// }
// void make_set(int n)
// {
//     for (int i = 1; i <= n; i++)
//     {
//         parent[i] = i;
//         sz[i] = 1;
//     }
// }

// void union_sets(int a, int b)
// {
//     a = find_set(a);
//     b = find_set(b);
//     if (a != b)
//     {
//         if (sz[a] < sz[b])
//             swap(a, b);
//         parent[b] = a;
//         if (sz[a] == sz[b])
//             sz[a]++;
//     }
// }