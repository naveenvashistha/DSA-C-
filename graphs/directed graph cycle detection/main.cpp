#include <bits/stdc++.h>

using namespace std;

//time: O(v + e)
//space: O(v)
bool dfs(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& pathvis)
{
  visited[node] = 1;
  pathvis[node] = 1;
  for(int i: adj[node])
  {
    if(!visited[i]){
      bool res = dfs(i, adj, visited, pathvis);
      if(res) return true;
    }
    else if(pathvis[i]) return true;
  }
  pathvis[node] = 0;
  return false;
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>>& edges) {
  // Write your code here.
  vector<vector<int>> adj(n + 1);
  vector<int> visited(n + 1, 0);
  vector<int> pathvis(n + 1, 0);
  for(auto i: edges) adj[i.first].push_back(i.second);
  for(int i = 1; i <= n; i++)
  {
    if(!visited[i]){
      bool res = dfs(i, adj, visited, pathvis);
      if(res) return 1;
    }
  }
  return 0;
}