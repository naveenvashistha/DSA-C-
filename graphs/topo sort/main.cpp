#include <bits/stdc++.h>

using namespace std;

//time: O(v + e)
//space: O(v)
void dfs(int node, vector<vector<int>>& adj, vector<int>& visited, stack<int>& st)
{
    visited[node] = 1;
    for(int i: adj[node])
    {
        if(!visited[i]) dfs(i, adj, visited, st);
    }
    st.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    vector<int> ans;
    vector<vector<int>> adj(v);
    vector<int> visited(v, 0);
    stack<int> st;
    for(auto i: edges) adj[i[0]].push_back(i[1]);
    for(int i = 0; i < v; i++)
    {
        if(!visited[i]) dfs(i, adj, visited, st);
    }
    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}