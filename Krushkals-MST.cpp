#include <bits/stdc++.h>
using namespace std;

int find(int node, vector<int> &parent)
{
    if (parent[node] == node)
        return node;

    return parent[node] = find(parent[node], parent);
}

void Union(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = find(u, parent);
    v = find(v, parent);

    if (rank[u] > rank[v])
    {
        parent[v] = u;
        rank[u]++;
    }
    else if (rank[u] <= rank[v])
    {
        parent[u] = v;
        rank[v]++;
    }
}

static bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
{
    return a.first < b.first;
}
int spanningTree(int v, vector<vector<int>> &ad)
{
    vector<pair<int, pair<int, int>>> adj;

    for (int i = 0; i < ad.size(); i++)
    {
        int w= ad[i][0], u = ad[i][1],v=ad[i][2];
        adj.push_back(make_pair(w, make_pair(u, v)));
    }

    sort(adj.begin(), adj.end(), cmp);

    vector<int> rank(v, 0);
    vector<int> parent(v, 0);
    for (int i = 0; i < v; i++)
        parent[i] = i;

    int ans = 0;
    for (auto it : adj)
    {
        int w = it.first;
        int u = it.second.first;
        int v = it.second.second;

        int parU = find(u, parent), parV = find(v, parent);
        if (parU != parV)
        {
            ans += w;
            Union(u, v, parent, rank);
        }
    }

    return ans;
}

int main()
{
    int V, E;
    cin >> V >> E;
    vector<vector<int>> adj(E);
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[i].push_back(w);
        adj[i].push_back(u);
        adj[i].push_back(v);
    }

    cout << spanningTree(V, adj) << endl;

    return 0;
}