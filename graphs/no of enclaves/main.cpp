#include <bits/stdc++.h>

using namespace std;

//orgasmic
//time: O(mxn)
//space: O(mxn)
void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& visited)
{
    visited[i][j] = 1;
    if(i - 1 >= 0 && grid[i - 1][j] == 1 && !visited[i - 1][j])
        dfs(i - 1, j, grid, visited);
    if(i + 1 < grid.size() && grid[i + 1][j] == 1 && !visited[i + 1][j])
        dfs(i + 1, j, grid, visited);
    if(j - 1 >= 0 && grid[i][j - 1] == 1 && !visited[i][j - 1])
        dfs(i, j - 1, grid, visited);
    if(j + 1 < grid[0].size() && grid[i][j + 1] == 1 && !visited[i][j + 1])
        dfs(i, j + 1, grid, visited);
}
int numEnclaves(vector<vector<int>>& grid) {
    int row = grid.size();
    int col = grid[0].size();
    vector<vector<int>> visited(row, vector<int>(col, 0));
    for(int i = 0; i < col; i++)
    {
        if(grid[0][i] == 1 && !visited[0][i]) dfs(0, i, grid, visited);
    }
    for(int i = 0; i < col; i++)
    {
        if(grid[row - 1][i] == 1 && !visited[row - 1][i]) dfs(row - 1, i, grid, visited);
    }
    for(int i = 1; i < row - 1; i++)
    {
        if(grid[i][0] == 1 && !visited[i][0]) dfs(i, 0, grid, visited);
    }
    for(int i = 1; i < row - 1; i++)
    {
        if(grid[i][col - 1] == 1 && !visited[i][col - 1]) dfs(i, col - 1, grid, visited);
    }
    int count = 0;
    for(int i = 1; i < row - 1; i++)
    {
        for(int j = 1; j < col - 1; j++)
        {
            if(grid[i][j] == 1 && !visited[i][j]) count++;
        }
    }
    return count;
}