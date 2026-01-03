vector<bool> visited;
vector<int> order;
vector<int> roots;
void dfs(int u, vector<vector<int>> const &adj, vector<int> &output)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (!visited[v])
        {
            dfs(v, adj, output);
        }
    }
    output.push_back(u);
}
void strongly_connected_components(vector<vector<int>> const &adj,
                                   vector<vector<int>> &components,
                                   vector<vector<int>> &adj_cond)
{
    int n = adj.size();
    components.clear();
    adj_cond.clear();
    visited.assign(n, false);
    order.clear();
    roots.assign(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i, adj, order);
        }
    }
    vector<vector<int>> adj_rev(n);
    for (int v = 0; v < n; v++)
    {
        for (int u : adj[v])
        {
            adj_rev[u].push_back(v);
        }
    }
    visited.assign(n, false);
    reverse(order.begin(), order.end());
    for (int v : order)
    {
        if (!visited[v])
        {
            vector<int> component;
            dfs(v, adj_rev, component);
            components.push_back(component);
            int root = *min_element(component.begin(), component.end());
            for (int u : component)
            {
                roots[u] = root;
            }
        }
    }
    adj_cond.resize(n);
    for (int v = 0; v < n; v++)
    {
        for (int u : adj[v])
        {
            if (roots[v] != roots[u])
            {
                adj_cond[roots[v]].push_back(roots[u]);
            }
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    vi a(n);
    forn(0, n) cin >> a[i];
    vector<vector<int>> adj(n);
    int m;
    cin >> m;
    forn(0, m)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
    }
    vector<vector<int>> components;
    vector<vector<int>> adj_cond;
    strongly_connected_components(adj, components, adj_cond);
    int cost = 0;
    int ans = 1;
    for (auto &component : components)
    {
        map<int, int> mp;
        for (int u : component)
        {
            mp[a[u]]++;
        }
        cost += (*mp.begin()).first;
        ans *= (*mp.begin()).second;
        ans %= mod;
    }
    cout << cost << " " << ans;
}