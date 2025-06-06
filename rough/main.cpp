#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    int u, v, w;
    vector<vector<pair<int, int>>> adj(n + 1);
    for(int i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<int> dist(n + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    dist[1] = 0;
    while(!pq.empty())
    {
        int orr = pq.top().first;
        int node = pq.top().second;
        cout << orr << " " << node << endl;
        pq.pop();
        if(node == n){
            cout << dist[n] << endl;
            return 0;
        }
        for(auto i: adj[node])
        {
            int ans = orr | i.second;
            if(ans < dist[i.first]){
                dist[i.first] = orr | i.second;
                pq.push({dist[i.first], i.first});
            }
        }
    }
}