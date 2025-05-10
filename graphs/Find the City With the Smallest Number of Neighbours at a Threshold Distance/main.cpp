#include <bits/stdc++.h>

using namespace std;

//orgasmic
//time: O(n^3)
//space: O(nxn)
int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    vector<vector<int>> adj(n, vector<int>(n, INT_MAX));
    for(auto i: edges)
    {
        adj[i[0]][i[1]] = i[2];
        adj[i[1]][i[0]] = i[2];
    }
    for(int i = 0; i < n; i++) adj[i][i] = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            for(int k = 0; k < n; k++)
            {
                adj[j][k] = min((long)adj[j][k], (long)adj[j][i] + adj[i][k]);
            }
        }
    }
    int minn = INT_MAX;
    int min_city = 0;
    for(int i = 0; i < n; i++)
    {
        int cnt = 0;
        for(int j = 0; j < n; j++)
        {
            if(adj[i][j] <= distanceThreshold) cnt++;
        }
        if(cnt <= minn){
            minn = cnt;
            min_city = i;
        }
    }
    return min_city;
}