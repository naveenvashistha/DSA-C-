#include <bits/stdc++.h>

using namespace std;

//ineffiecint as it will not necessary choose the shortest path first time and might
//go through it again to find the shortest path
//time: O(v + e)
//space: O(v)
vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges)
{
    // Write your code here
    vector<vector<pair<int, int>>> adj(n);
    queue<pair<int, int>> q;
    vector<int> dist(n, -1);
    for(auto i: edges)
    {
        adj[i[0]].push_back({i[1], i[2]});
    }
    q.push({0, 0});
    dist[0] = 0;
    while(!q.empty())
    {
        int node = q.front().first;
        int d = q.front().second;
        q.pop();
        for(auto i: adj[node])
        {
            if(dist[i.first] == -1 || dist[i.first] > d + i.second){
                q.push({i.first, d + i.second});
                dist[i.first] = i.second + d;
            }
        }
    }
    return dist;
}

//orgasmic
//time: O(v + e)
//space: O(v)
void dfs(int node, vector<vector<pair<int, int>>>& adj, vector<int>& visited, stack<int>& st)
{
    visited[node] = 1;
    for(auto i: adj[node])
    {
        if(!visited[i.first])
            dfs(i.first, adj, visited, st);
    }
    st.push(node);
}

vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges)
{
    // Write your code here
    vector<vector<pair<int, int>>> adj(n);
    stack<int> st;
    vector<int> dist(n, -1);
    vector<int> visited(n);
    dist[0] = 0;
    for(auto i: edges)
    {
        adj[i[0]].push_back({i[1], i[2]});
    }
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            dfs(i, adj, visited, st);
        }
    }
    while(0 != st.top())
        st.pop();
    while(!st.empty())
    {
        int node = st.top();
        for(auto i: adj[node])
        {
            if(dist[i.first] == -1 || dist[i.first] > dist[node] + i.second)
                dist[i.first] = dist[node] + i.second;
        }
        st.pop();
    }
    return dist;
}
