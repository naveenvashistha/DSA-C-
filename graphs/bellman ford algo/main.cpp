#include <bits/stdc++.h>

using namespace std;

//orgasmic
//time: O(n^3)
//space: O(1)
void floydWarshall(vector<vector<int>> &dist) {
    // Code here
    int v = dist.size();
    for(int i = 0; i < v; i++)
    {
        for(int j = 0; j < v; j++)
        {
            for(int k = 0; k < v; k++)
            {
                if(dist[j][i] != 1e8 && dist[i][k] != 1e8)
                    dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
            }
        }
    }
}