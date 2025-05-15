#include <bits/stdc++.h>

using namespace std;

//orgasmic
//time: O(vxe)
//space: O(v)
vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
    // Code here
    vector<int> dist(V, 1e8);
    dist[src] = 0;
    for(int i = 0; i < V - 1; i++)
    {
        for(auto j: edges)
        {
            if(dist[j[0]] != 1e8 && dist[j[0]] + j[2] < dist[j[1]]){
                dist[j[1]] = dist[j[0]] + j[2];
            }
        }
    }
    for(auto j: edges){
        if(dist[j[0]] != 1e8 && dist[j[0]] + j[2] < dist[j[1]]){
            return {-1};
        }
    }
    return dist;
}