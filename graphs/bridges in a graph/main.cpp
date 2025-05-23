#include <bits/stdc++.h>

using namespace std;

//time: O(2e)
//space: O(v)
class Solution {
public:
    void dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& visited, vector<vector<int>>& ans, vector<int>& ins, vector<int>& low, int& t)
    {
        visited[node] = 1;
        ins[node] = t;
        low[node] = t;
        for(int i: adj[node])
        {
            if(i == parent) continue;
            if(!visited[i]){
                t++;
                dfs(i, node, adj, visited, ans, ins, low, t);
            }
            low[node] = min(low[node], low[i]);
            if(ins[node] < low[i]) ans.push_back({node, i});
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> ins(n, 0);
        vector<int> low(n, 0);
        vector<int> visited(n, 0);
        int t = 1;
        vector<vector<int>> ans;
        vector<vector<int>> adj(n);
        for(auto i: connections){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        dfs(0, -1, adj, visited, ans, ins, low, t);
        return ans;
    }
};