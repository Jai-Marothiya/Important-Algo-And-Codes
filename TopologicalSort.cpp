#include <bits/stdc++.h>
using namespace std;

vector<int> topoSort(int V, unordered_map<int, vector<int>> &adj)
{
    vector<int> indegree(V, 0);

    for (int i = 0; i < V; i++)
    {
        int u = i;
        for (auto v : adj[u])
        {
            indegree[v]++;
        }
    }

    queue<int> q;

    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> ans;
    vector<bool> vis(V, false);

    while (!q.empty())
    {
        int top = q.front();
        q.pop();
        ans.push_back(top);

        for (auto nbr : adj[top])
        {
            indegree[nbr]--;
            if (indegree[nbr] == 0)
                q.push(nbr);
        }
    }

    return ans;
}


int main(){
    int V;
    unordered_map<int, vector<int>> adj;
    cin>>V;
    for(int i=0;i<V-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    vector<int>ans=topoSort(V,adj);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}