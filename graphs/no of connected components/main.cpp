#include <bits/stdc++.h>

using namespace std;

//if adj list is given
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

//if adj matrix is given
//time: O(v^2)
//space: O(v)
void dfs(vector<vector<int>>& isConnected, vector<int>& visited, int node)
{
    visited[node] = 1;
    
    for(int i = 0; i < isConnected.size(); i++)
    {
        if(i != node && isConnected[node][i] == 1 && visited[i] == 0){
            dfs(isConnected, visited, i);
        }
    }
}
int findCircleNum(vector<vector<int>>& isConnected) {
    vector<int> visited(isConnected.size(), 0);
    int count = 0;
    for(int i = 0; i < isConnected.size(); i++)
    {
        cout << visited[i] << endl;
        if(!visited[i]){
            count++;
            dfs(isConnected, visited, i);
        }
    }
    return count;
}