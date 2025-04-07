#include <bits/stdc++.h>

using namespace std;

//using bfs
//time: O(n + 2e)
//space: O(n)
bool bfs(vector<vector<int>>& adj, int visited[], int node)
{
    queue<pair<int, int>> q;
    q.push({node, -1});
    visited[node] = 1;
    while(!q.empty())
    {
        pair<int, int> p = q.front();
        int n = p.first;
        int source = p.second;
        q.pop();
        for(int k: adj[n])
        {
            if(!visited[k])
            {
                visited[k] = 1;
                q.push({k, n});
            }
            else if(k != source) return true;
        }
    }
    return false;
}
bool isCycle(int V, vector<vector<int>>& edges) {
    // Code here
    vector<vector<int>> adj(V);
    int visited[V] = {0};
    for(auto i: edges)
    {
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
    }
    for(int i = 0; i < V; i++)
    {
        if(!visited[i]){
            bool res = bfs(adj, visited, i);
            if(res) return true;
        }
    }
    return false;
}

//using dfs
//time: O(n + 2e)
//space: O(n)
bool dfs(vector<vector<int>>& adj, int visited[], int node, int source)
{
    visited[node] = 1;
    for(int i: adj[node])
    {
        if(!visited[i]){
            bool res = dfs(adj, visited, i, node);
            if(res) return true;
        }
        else if(source != i) return true;
    }
    return false;
}
bool isCycle(int V, vector<vector<int>>& edges) {
    // Code here
    vector<vector<int>> adj(V);
    int visited[V] = {0};
    for(auto i: edges)
    {
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
    }
    for(int i = 0; i < V; i++)
    {
        if(!visited[i]){
            bool res = dfs(adj, visited, i, -1);
            if(res) return true;
        }
    }
    return false;
}