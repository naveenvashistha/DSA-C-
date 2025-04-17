#include <bits/stdc++.h>

using namespace std;

//using priority queue
//time: O(ElogV)
//space: O(V)
vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
    // Code here
    priority_queue<pair<int, int>> q;
    vector<int> dist(V, -1);
    vector<vector<pair<int, int>>> adj(V);
    q.push({0, src});
    dist[src] = 0;
    for(auto i: edges)
    {
        adj[i[0]].push_back({i[1], i[2]});
        adj[i[1]].push_back({i[0], i[2]});
    }
    while(!q.empty())
    {
        int node = q.top().second;
        int d = q.top().first;
        q.pop();
        for(auto i: adj[node])
        {
            if(dist[i.first] == -1 || dist[i.first] > d + i.second)
            {
                dist[i.first] = d + i.second;
                q.push({dist[i.first], i.first});
            }
        }
    }
    return dist;
}

//using sets
//time: O(ElogV)
//space: O(V)
vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
    // Code here
    set<pair<int, int>> q;
    vector<int> dist(V, -1);
    vector<vector<pair<int, int>>> adj(V);
    q.insert({0, src});
    dist[src] = 0;
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
            }
        }
    }
    return dist;
}