// BFS VERSION

// void solve()
// {
//     int n, m;
//     cin >> n >> m;
//     vi adj[n + 1];
//     vi indegree(n + 1, 0);
//     vi visited(n + 1, 0);
//     vi ans;
//     for (int i = 0; i < m; i++)
//     {
//         int u, v;
//         cin >> u >> v;
//         adj[u].pb(v);
//         indegree[v]++;
//     }
//     queue<int> q;
//     for (int i = 1; i <= n; i++)
//     {
//         if (indegree[i] == 0)
//         {
//             q.push(i);
//         }
//     }

// DFS VERSION

// int n; // number of vertices
// vector<vector<int>> adj; // adjacency list of graph
// vector<bool> visited;
// vector<int> ans;

// void dfs(int v) {
//     visited[v] = true;
//     for (int u : adj[v]) {
//         if (!visited[u])
//             dfs(u);
//     }
//     ans.push_back(v);
// }

// void topological_sort() {
//     visited.assign(n, false);
//     ans.clear();
//     for (int i = 0; i < n; ++i) {
//         if (!visited[i])
//             dfs(i);
//     }
//     reverse(ans.begin(), ans.end());
// }

//     while (!q.empty())
//     {
//         int node = q.front();
//         ans.pb(node);
//         q.pop();
//         for (auto it : adj[node])
//         {
//             indegree[it]--;
//             if (indegree[it] == 0)
//             {
//                 q.push(it);
//             }
//         }
//     }

//     if (ans.size() != n)
//     {
//         cout << "Sandro fails.";
//         return;
//     }
//     else
//     {
//         for (auto i : ans)
//         {
//             cout << i << " ";
//         }
//     }
// }