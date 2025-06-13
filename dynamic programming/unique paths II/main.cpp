#include <bits/stdc++.h>

using namespace std;

//memoization
//time: O(m*n)
//space: O(m*n)
class Solution {
public:
    int helper(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& dp)
    {
        if(dp[r][c] != -1) return dp[r][c];
        if(grid[r][c] == 1) return 0;
        if(r == grid.size() - 1 && c == grid[0].size() - 1) return 1;
        int down = 0, right = 0;
        if(r + 1 < grid.size()) down = helper(r + 1, c, grid, dp);
        if(c + 1 < grid[0].size()) right = helper(r, c + 1, grid, dp);
        return dp[r][c] = down + right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
        return helper(0, 0, grid, dp);
    }
};


//space optimization
//time: O(m*n)
//space: O(m*n)
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        vector<vector<long long>> dp(grid.size(), vector<long long>(grid[0].size(), 0));
        int m = grid.size();
        int n = grid[0].size();
        for(int i = m - 1; i >= 0; i--)
        {
            for(int j = n - 1; j >= 0; j--)
            {
                long long down = 0, right = 0;
                if(grid[i][j] == 1) continue;
                if(i == m - 1 && j == n - 1){
                    dp[i][j] = 1;
                    continue;
                }
                if(i + 1 < m ) down = dp[i + 1][j];
                if(j + 1 < n) right = dp[i][j + 1];
                dp[i][j] = down + right;
            }
        }
        return dp[0][0];
    }
};