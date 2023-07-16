#include <bits/stdc++.h>
using namespace std;

int main()
{
    int v, E;
    cin >> v >> E;
    vector<vector<int>> ad(E);
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        ad[i].push_back(w);
        ad[i].push_back(u);
        ad[i].push_back(v);
    }

    // Prim's Algorithm to find MST
    // Create Adjcency list
    unordered_map<int, vector<pair<int, int>>> adj;
    for (int i = 0; i < E; i++)
    {
        int u = ad[i][0], v = ad[i][1], w = ad[i][2];
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    // create 3 DS key,mst,parent
    vector<int> key(v, INT_MAX);
    vector<bool> mst(v, false);
    vector<int> parent(v, -1);
    // To make TC=O(nlog(n)) we use priority queue so we don't need to search minimum element int key
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // lets take 0 as starting point
    int u = 0;
    key[u] = 0;
    pq.push(make_pair(0, 0));

    while (!pq.empty())
    {

        // find key with minimum value
        int u = pq.top().second;
        pq.pop();
        // set mst[u]=true
        mst[u] = true;

        for (auto it : adj[u])
        {
            int v = it.first, w = it.second;
            if (w < key[v] && mst[v] == false)
            {
                key[v] = w;
                parent[v] = u;
                pq.push(make_pair(w, v));
            }
        }
    }
    int ans = 0;
    for (int i = 1; i < v; i++)
    {
        int u = parent[i];
        for (auto it : adj[u])
        {
            if (it.first == i)
            {
                ans += it.second;
            }
        }
    }

    cout<<ans<<endl;
}