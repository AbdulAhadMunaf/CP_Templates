void dijkstra(int s, vi &d, vector<vector<pii>> &adj)
{
    visited.assign(MAXN, 0);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s});
    d[s] = 0;
    // distance , node

    while (!pq.empty())
    {
        pii node = pq.top();
        pq.pop();
        int distance = node.first;
        int index = node.second;
        if (visited[index])
        {
            continue;
        }
        visited[index] = 1;
        for (auto it : adj[index])
        {
            if (d[index] + it.second < d[it.first])
            {
                d[it.first] = d[index] + it.second;
                pq.push({d[it.first], it.first});
            }
        }
    }
}
