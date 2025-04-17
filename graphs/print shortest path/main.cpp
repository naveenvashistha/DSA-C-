#include <bits/stdc++.h>

using namespace std;

//time: O(elogv)
//space: O(v)
vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
    // Code here
    set<pair<int, int>> q;
    vector<int> dist(n + 1, -1);
    vector<int> parent(n + 1, -1);
    vector<vector<pair<int, int>>> adj(n + 1);
    q.insert({0, 1});
    dist[1] = 0;
    for(auto i: edges)
    {
        adj[i[0]].push_back({i[1], i[2]});
        adj[i[1]].push_back({i[0], i[2]});
    }
    while(!q.empty())
    {
        auto it = q.begin();
        int node = it->second;
        int d = it->first;
        q.erase(it);
        for(auto i: adj[node])
        {
            if(dist[i.first] == -1 || dist[i.first] > d + i.second)
            {
                if(dist[i.first] > d + i.second){
                    q.erase({dist[i.first], i.first});
                }
                dist[i.first] = d + i.second;
                q.insert({dist[i.first], i.first});
                parent[i.first] = node;
            }
        }
    }
    if(dist[n] == -1) return {-1};
    vector<int> ans;
    ans.push_back(n);
    int i = n;
    while(i != 1)
    {
        ans.push_back(parent[i]);
        i = parent[i];
    }
    ans.push_back(dist[n]);
    reverse(ans.begin(), ans.end());
    return ans;
}