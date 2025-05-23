#include <bits/stdc++.h>

using namespace std;

//time: O(v + e)
//space: O(v)
class Solution {
  public:
    int timee = 1;
    void dfs(int node, int parent, vector<int> adj[], vector<int>& visited, vector<int>& mark, vector<int>& ins, vector<int>& low)
    {
        visited[node] = 1;
        low[node] = ins[node] = timee;
        int child = 0;
        for(int i: adj[node]){
            if(i == parent) continue;
            if(!visited[i]){
                timee++;
                child++;
                dfs(i, node, adj, visited, mark, ins, low);
                low[node] = min(low[node], low[i]);
                if(ins[node] <= low[i] && parent != -1) mark[node] = 1;
            }
            else{
                low[node] = min(ins[i], low[node]);
            }
        }
        if(child > 1 && parent == -1) mark[node] = 1;
    }
    vector<int> articulationPoints(int V, vector<int> adj[]) {
        // Code here
        vector<int> visited(V, 0);
        vector<int> low(V, 0);
        vector<int> ins(V, 0);
        vector<int> mark(V, 0);
        vector<int> ans;
        dfs(0, -1, adj, visited, mark, ins, low);
        for(int i = 0; i < V; i++){
            if(mark[i] == 1) ans.push_back(i);
        }
        if(ans.size() == 0) return {-1};
        return ans;
    }
};