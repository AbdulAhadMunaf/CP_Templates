const int INF = 1e17;
const int NINF = 1e17 * (-1LL);
struct edge
{
    int from;
    int to;
    int weight;
};
int n, m;
void solve()
{
    cin >> n >> m;
    vector<edge> edges(m);
    vi d(n + 1, INF);

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        w *= -1;
        edges[i].from = u;
        edges[i].to = v;
        edges[i].weight = w;
    }
    d[1] = 0;
    for (int i = 1; i < n; i++)
    {
        for (auto it : edges)
        {
            int u = it.from;
            int v = it.to;
            int w = it.weight;
            if (d[u] == INF)
            {
                continue;
            }
            d[v] = min(d[v], d[u] + w);
            d[v] = max(d[v], NINF);
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (auto it : edges)
        {
            int u = it.from;
            int v = it.to;
            int w = it.weight;
            if (d[u] == INF)
            {
                continue;
            }
            d[v] = max(d[v], NINF);
            if (d[u] + w < d[v])
            {
                d[v] = NINF;
            }
        }
    }
    if (d[n] == NINF)
    {
        cout << -1;
    }
    else
    {
        cout << d[n] * (-1);
    }
}