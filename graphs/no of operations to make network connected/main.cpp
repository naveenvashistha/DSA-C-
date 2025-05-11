#include <bits/stdc++.h>

using namespace std;

class disjoint{
        public:
    vector<int> rank, size, parent;
    disjoint(int n){
        //considering 1 based indexing
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for(int i = 0; i < n + 1; i++) parent[i] = i;
    }

    int findUParent(int u)
    {
        if(u == parent[u]) return u;
        return parent[u] = findUParent(parent[u]);
    }

    void unionByRank(int u, int v)
    {
        int p_u = findUParent(u);
        int p_v = findUParent(v);
        if(p_u == p_v) return;
        if(rank[p_u] < rank[p_v]){
            parent[p_u] = p_v;
        }
        else if(rank[p_v] < rank[p_u]){
            parent[p_v] = p_u;
        }
        else{
            parent[p_u] = p_v;
            rank[p_v]++;
        }
    }

    int unionBySize(int u, int v)
    {
        int p_u = findUParent(u);
        int p_v = findUParent(v);
        if(p_u == p_v) return 1;
        if(size[p_u] <= size[p_v]){
            parent[p_u] = p_v;
            size[p_v] += size[p_u];
        }
        else if(size[p_v] < size[p_u]){
            parent[p_v] = p_u;
            size[p_u] += size[p_v];
        }
        return 0;
    }

};

//strivers
//time: O(e*4a*2) + O(n)
//space: O(2N)
int makeConnected(int n, vector<vector<int>>& connections) {
    disjoint d(n);
    int comp = 0;
    int extraEdges = 0;
    for(auto i: connections)
    {
        extraEdges += d.unionBySize(i[0], i[1]);
    }
    for(auto i = 0; i < n; i++){
        if(i == d.parent[i]) comp++;
    }
    if(extraEdges >= (comp - 1)) return comp - 1;
    return -1;
}

//my solution
//time: O(v + 2e)
//space: O(v)
void dfs(vector<int>& visited, vector<vector<int>>& adj, int node)
{
    visited[node] = 1;
    for(int i: adj[node])
    {
        if(!visited[i])
            dfs(visited, adj, i);
    }
}
int makeConnected(int n, vector<vector<int>>& connections) {
    vector<int> visited(n, 0);
    vector<vector<int>> adj(n);
    for(auto i: connections){
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
    }
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        if(!visited[i]){
            count++;
            dfs(visited, adj, i);
        }
    }
    int a = connections.size() - (n - 1);
    if(a >= 0) return count - 1;
    return -1;
}