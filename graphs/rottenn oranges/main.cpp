#include <bits/stdc++.h>

using namespace std;

//orgasmic
//time: O(mxn)
//space: O(mxn)
int orangesRotting(vector<vector<int>>& grid) {
    queue<pair<int, int>> q;
    int total_orange = 0;
    int total_time = 0;
    int count = 0;
    for(int i = 0; i < grid.size(); i++)
    {
        for(int j = 0; j < grid[0].size(); j++)
        {
            if(grid[i][j] == 2) q.push({i, j});
            if(grid[i][j] != 0) total_orange++;
        }
    }
    while(true)
    {
        int size = q.size();
        count += size;
        for(int m = 0; m < size; m++)
        {
            pair<int, int> p = q.front();
            int i = p.first;
            int j = p.second;
            q.pop();
            if(i - 1 >= 0 && grid[i - 1][j] == 1){
                grid[i - 1][j] = 2;
                q.push({i - 1, j});
            }
            if(j - 1 >= 0 && grid[i][j - 1] == 1){
                grid[i][j - 1] = 2;
                q.push({i, j - 1});
            }
            if(j + 1 < grid[0].size() && grid[i][j + 1] == 1){
                grid[i][j + 1] = 2;
                q.push({i, j + 1});
            }
            if(i + 1 < grid.size() && grid[i + 1][j] == 1){
                grid[i + 1][j] = 2;
                q.push({i + 1, j});
            }
        }
        if(!q.empty()) total_time++;
        else break; 
    }
    if(count == total_orange) return total_time;
    return -1;
}