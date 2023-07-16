#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

namespace Bridge
{

    vector<pair<int, int>> bridges;
    vector<bool> visited;
    vector<int> tin, low;
    int timer = 0;

    void IS_BRIDGE(int u, int v)
    {
        if (u > v)
            swap(u, v);
        bridges.push_back({u, v});
    }

    void dfs(vector<vector<int>> &adj, int cur, int par = -1)
    {
        visited[cur] = true;
        tin[cur] = low[cur] = timer++;
        for (int to : adj[cur])
        {
            if (to == par)
            {
                continue;
            }
            if (visited[to])
            {
                low[cur] = min(low[cur], tin[to]);
            }
            else
            {
                dfs(adj, to, cur);
                low[cur] = min(low[cur], low[to]);
                if (low[to] > tin[cur])
                    IS_BRIDGE(cur, to);
            }
        }
    }

    void find_bridges(vector<vector<int>> &adj)
    {
        bridges.clear();
        timer = 0;
        int n = (int)adj.size() - 1;
        visited.assign(n + 1, false);
        tin.assign(n + 1, -1);
        low.assign(n + 1, -1);
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                dfs(adj, i);
            }
        }
    }

}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    Bridge::find_bridges(adj);

    set<pair<int, int>> st;

    for (auto it : Bridge::bridges)
        st.insert(it);

    for (auto it : st)
        cout << it.first << " " << it.second << "\n";

    return 0;
}