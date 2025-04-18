#include <bits/stdc++.h>

using namespace std;

//orgasmic
//time: O(4NMLOG(NM))
//space: O(mxn)
int minimumEffortPath(vector<vector<int>>& heights) {
    int rows = heights.size();
    int cols = heights[0].size();
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({0, {0, 0}});
    vector<vector<int>> diff(rows, vector<int>(cols, INT_MAX));
    diff[0][0] = 0;
    int r[] = {0, 0, -1, 1};
    int c[] = {-1, 1, 0, 0};
    while(!pq.empty())
    {
        pair<int, int> node = pq.top().second;
        int effort = pq.top().first;
        pq.pop();
        if(node.first == rows - 1 && node.second == cols - 1) return effort;
        for(int i = 0 ; i < 4; i++)
        {
            int nrow = node.first + r[i];
            int ncol = node.second + c[i];
            if(nrow < rows && nrow >= 0 && ncol < cols && ncol >= 0)
            {
                int e = abs(heights[nrow][ncol] - heights[node.first][node.second]);
                int neweffort = max(e, effort);
                if(neweffort < diff[nrow][ncol]){
                    pq.push({neweffort, {nrow, ncol}});
                    diff[nrow][ncol] = neweffort;
                }
            }
        }
    }
    return diff[rows - 1][cols - 1];
}