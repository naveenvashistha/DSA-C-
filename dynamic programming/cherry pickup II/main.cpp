#include <bits/stdc++.h>

using namespace std;

//memoization
//time: O(m*n*n*9)
//space: O(m*n*n)
class Solution {
public:
    int helper(int i, int j1, int j2, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp)
    {
        if(j1 < 0 || j2 < 0 || j1 >= grid[0].size() || j2 >= grid[0].size()) return INT_MIN;
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        if(i == grid.size() - 1){
            if(j1 == j2) return dp[i][j1][j2] = grid[i][j1];
            return dp[i][j1][j2] = grid[i][j1] + grid[i][j2];
        }
        int maxi = INT_MIN;
        for(int k = -1; k <= 1; k++){
            for(int l = -1; l <= 1; l++)
            {
                maxi = max(maxi, helper(i + 1, j1 + k, j2 + l, grid, dp));
            }
        }
        if(j1 == j2) return dp[i][j1][j2] = maxi + grid[i][j1];
        return dp[i][j1][j2] = maxi + grid[i][j1] + grid[i][j2];
    }
    int cherryPickup(vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(grid[0].size(), -1)));
        return helper(0, 0, grid[0].size() - 1, grid, dp);   
    }
};

//tabulation
//time: same as above
//space: same as above
int cherryPickup(vector<vector<int>>& grid) {
    vector<vector<vector<int>>> dp(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(grid[0].size(), -1)));
    int m = grid.size();
    int n = grid[0].size();
    for(int i = m - 1; i >= 0; i--)
    {
        for(int j1 = n - 1; j1 >= 0; j1--)
        {
            for(int j2 = n - 1; j2 >= 0; j2--)
            {
                if(i == m - 1){
                    if(j1 == j2) dp[i][j1][j2] = grid[i][j1];
                    else dp[i][j1][j2] = grid[i][j1] + grid[i][j2];
                    continue;
                }
                int maxi = INT_MIN;
                for(int k = -1; k <= 1; k++)
                {
                    for(int l = -1; l <= 1; l++)
                    {
                        if(j1 + k < 0 || j2 + l < 0 || j1 + k >= n || j2 + l >= n) continue;
                        if(j1 == j2) maxi = max(maxi, dp[i + 1][j1 + k][j2 + l] + grid[i][j1]);
                        else maxi = max(maxi, dp[i + 1][j1 + k][j2 + l] + grid[i][j1] + grid[i][j2]);
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }
    return dp[0][0][n - 1];  
}

