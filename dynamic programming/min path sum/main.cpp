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
        if(r == grid.size() - 1 && c == grid[0].size() - 1) return dp[r][c] = grid[r][c];
        int down = INT_MAX, right = INT_MAX;
        if(r + 1 < grid.size()) down = helper(r + 1, c, grid, dp);
        if(c + 1 < grid[0].size()) right = helper(r, c + 1, grid, dp);
        return dp[r][c] = grid[r][c] + min(down, right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
        return helper(0, 0, grid, dp);
    }
};


//tabulation
//time: O(m*n)
//space: O(m*n)
int minPathSum(vector<vector<int>>& grid) {
    vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
    int m = grid.size();
    int n = grid[0].size();
    for(int i = m - 1; i >= 0; i--)
    {
        for(int j = n - 1; j >= 0; j--)
        {
            if(i == m - 1 && j == n - 1){
                dp[i][j] = grid[i][j];
                continue;
            }
            int down = INT_MAX, right = INT_MAX;
            if(i + 1 < m) down = dp[i + 1][j];
            if(j + 1 < n) right = dp[i][j + 1];
            dp[i][j] = grid[i][j] + min(down, right);
        }
    }
    return dp[0][0];
}

