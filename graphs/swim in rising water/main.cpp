#include <bits/stdc++.h>

using namespace std;

//orgasmic
//time: O(n^2logn)
//space: O(n^2)
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<int>> visited(n, vector<int>(n, 0));
        int r[] = {-1, 1, 0, 0};
        int c[] = {0, 0, -1, 1};
        pq.push({grid[0][0], 0, 0});
        visited[0][0] = 1;
        while(!pq.empty())
        {
            vector<int> temp = pq.top();
            int t = temp[0];
            int i = temp[1];
            int j = temp[2];
            pq.pop();
            if(i == n - 1 && j == n - 1) return t;
            for(int k = 0; k < 4; k++)
            {
                int nrow = i + r[k];
                int ncol = j + c[k];
                if(nrow >= 0 && ncol >= 0 && ncol < n && nrow < n && !visited[nrow][ncol]){
                    visited[nrow][ncol] = 1;
                    if(grid[nrow][ncol] < t) pq.push({t, nrow, ncol});
                    else pq.push({grid[nrow][ncol], nrow, ncol});
                }
            }
        }
        return 0;
    }
};