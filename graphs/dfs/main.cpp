#include <bits/stdc++.h>

using namespace std;

//time: O(n + 2e)
//space: O(n)
void traversal(vector<int>& ans, vector<vector<int>>& adj, int visited[], int node)
{
    ans.push_back(node);
    for(int i: adj[node]){
        if(!visited[i]){
            visited[i] = 1;
            traversal(ans, adj, visited, i);
        }
    }
}
vector<int> dfs(vector<vector<int>>& adj) {
    // Code here
    int visited[adj.size()] = {0};
    visited[0] = 1;
    vector<int> ans;
    traversal(ans, adj, visited, 0);
    return ans;
}