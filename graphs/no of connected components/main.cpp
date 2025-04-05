#include <bits/stdc++.h>

using namespace std;

//time: O(n + 2e)
//space: O(n)
void dfs(vector<vector<int>>& adj, int visited[], int i)
{
    visited[i] = i;
    for(int j: adj[i])
    {
        if(!visited[j]) dfs(adj, visited, j);
    }
}
int countComponents(int n, vector<vector<int>>& edges) {
    vector<vector<int>> adj(n);
    for(auto i: edges)
    {
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
    }
    int visited[n] = {0};
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        if(!visited[i]){
            count++;
            dfs(adj, visited, i);
        }
    }
    return count;
}