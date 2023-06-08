

// void dijkstra(int s, vi &d, vector<vector<pii>> &adj)
// {
//     visited.assign(MAXN, 0);
//     priority_queue<pii, vector<pii>, greater<pii>> pq;
//     pq.push({0, s});
//     d[s] = 0;
//     // distance , node

//     while (!pq.empty())
//     {
//         pii node = pq.top();
//         pq.pop();
//         int distance = node.first;
//         int index = node.second;
//         if (visited[index])
//         {
//             continue;
//         }
//         visited[index] = 1;
//         for (auto it : adj[index])
//         {
//             if (d[index] + it.second < d[it.first])
//             {
//                 d[it.first] = d[index] + it.second;
//                 pq.push({d[it.first], it.first});
//             }
//         }
//     }
// }

#include <bits/stdc++.h>
using namespace std;
#define nl cout << "\n";
#define forn(a, b) for (int i = a; i < b; i++)
#define pii pair<int, int>
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define all(a) a.begin(), a.end()
#define vi vector<int>
#define hhh cout << "here" << endl;
#define int long long int
#define ld long double
#define mod1 1000000007
#define mod2 998244353
const int MAXN = 1e5 + 10;
const int INF = 1e16;
vector<pii> adj[MAXN];
vi d(MAXN, INF);
vi visited(MAXN, 0);
void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
    }

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 1});
    d[1] = 0;
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
    for (int i = 1; i <= n; i++)
    {
        cout << d[i] << " ";
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
        nl;
    }
    return 0;
}