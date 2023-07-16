#include<bits/stdc++.h>
using namespace std;

int find(int node,vector<int>&par){
        if(node==par[node])return node;
        
        return par[node]=find(par[node],par);
}
bool Union(int u,int v,vector<int>&par,vector<int>&rank){
    u=find(u,par);
    v=find(v,par);
    // cout<<u<<" "<<v<<endl;
    // cout<<"par: "<<paru<<" "<<parv<<endl;
    if(u==v)return true;
    if(rank[u]>rank[v]){
        par[v]=u;
        rank[u]+=rank[v];
    }else{
        par[u]=v;
        rank[v]+=rank[u];
    }
    return false;
}

int detectCycle(int V, vector<vector<int>>&ad)
{
    vector<int> par(V),rank(V,0),vis(V,0);
    
    for(int i=0;i<V;i++){
        par[i]=i;
    }
    // cout<<"i& j"<<endl;
    for(int i=0;i<ad.size();i++){
        for(auto j:ad[i]){
            int u=i,v=j;
            // cout<<i<<" "<<j<<endl;
            if(vis[j]==0 && Union(u,v,par,rank)==true) return 1;
        }
        vis[i]=1;
    }
    return 0;
}

int main(){
    int V,E;
    vector<vector<int>>adj(V);
    cin>>V>>E;
    for(int i=0;i<E;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout<<detectCycle(V,adj)<<endl;
    return 0;
}