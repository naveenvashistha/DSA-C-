#include <bits/stdc++.h>

using namespace std;

//time: O(v + 2e)
//space: O(v)
vector<int> shortestPath(vector<vector<int>>& adj, int src) {
    // code here
    queue<pair<int, int>> q;
    vector<int> dist(adj.size(), -1);
    dist[src] = 0;
    q.push({src, 0});
    while(!q.empty())
    {
        int node = q.front().first;
        int d = q.front().second;
        q.pop();
        for(auto i: adj[node])
        {
            if(dist[i] == -1){
                dist[i] = d + 1;
                q.push({i, d + 1});
            }
        }
    }
    return dist;
}