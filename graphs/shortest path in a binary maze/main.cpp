#include <bits/stdc++.h>

using namespace std;

//time: O(8xmxn)
//space: O(mxn)
int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    if(grid[rows - 1][cols - 1] == 1 || grid[0][0] == 1) return -1;
    queue<pair<pair<int, int>, int>> q;
    vector<vector<int>> dist(rows, vector<int>(cols, -2));
    q.push({{0, 0}, 0});
    dist[0][0] = 0;
    vector<int> r = {-1, 1, 0, 0, -1, 1, -1, 1};
    vector<int> c = {0, 0, -1, 1, -1, -1, 1, 1};
    while(!q.empty())
    {
        pair<int, int> node = q.front().first;
        int d = q.front().second;
        q.pop();
        for(int i = 0; i < 8; i++)
        {
            int nrow = node.first + r[i];
            int ncol = node.second + c[i];
            if(nrow >= 0 && nrow < rows && ncol >= 0 && ncol < cols && grid[nrow][ncol] == 0 && dist[nrow][ncol] == -2)
            {
                dist[nrow][ncol] = d + 1;
                q.push({{nrow, ncol}, d + 1});
            }
        }
    }
    return dist[rows - 1][cols - 1] + 1;
}