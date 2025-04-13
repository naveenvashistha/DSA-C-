#include <bits/stdc++.h>

using namespace std;


//time: O(mxn)
//space: O(mxn)
void dfs(int** grid, vector<vector<int>> &visited, int i, int j, int& rows, int& cols)
{
   visited[i][j] = 1;
   int VHdirecRow[] = {-1, 0, 1, 0, -1, 1, 1, -1};
   int VHdirecCol[] = {0, -1, 0, 1, -1, -1, 1, 1};
   for(int k = 0; k < 8; k++)
   {
      int r = i + VHdirecRow[k];
      int c = j + VHdirecCol[k];
      if(r >= 0 && r < rows && c >= 0 && c < cols && !visited[r][c] && grid[r][c] == 1)
            dfs(grid, visited, r, c, rows, cols);
   }
}

int getTotalIslands(int** grid, int n, int m)
{
   // Write your code here.
   int count = 0;
   vector<vector<int>> visited(n, vector<int>(m, 0));
   for(int i = 0; i < n; i++)
   {
      for(int j = 0; j < m; j++)
      {
            if(grid[i][j] == 1 && !visited[i][j])
            {
               count++;
               dfs(grid, visited, i, j, n, m);
            }
      }
   }
   return count;
}
