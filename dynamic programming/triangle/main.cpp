#include <bits/stdc++.h>

using namespace std;

//memoization
//time: O(all the cells in grid)
//space: O(all the cells in the grid)
class Solution {
public:
    int helper(int r, int c, vector<vector<int>>& triangle, vector<vector<int>>& dp)
    {
        if(r == triangle.size() - 1) return dp[r][c] = triangle[r][c];

        if(dp[r][c] != -1) return dp[r][c];

        int a = helper(r + 1, c, triangle, dp);
        int b = helper(r + 1, c + 1, triangle, dp);

        return dp[r][c] = triangle[r][c] + min(a, b);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(), vector<int>(triangle[triangle.size() - 1].size(), -1));
        return helper(0, 0, triangle, dp);
    }
};


//tabulation
//time: same as above
//space: same as above
int minimumTotal(vector<vector<int>>& triangle) {
    vector<vector<int>> dp(triangle.size(), vector<int>(triangle[triangle.size() - 1].size(), -1));
    for(int i = triangle.size() - 1; i >= 0; i--)
    {
        for(int j = triangle[i].size() - 1; j >= 0; j--)
        {
            if(i == triangle.size() - 1){
                dp[i][j] = triangle[i][j];
                continue;
            }
            dp[i][j] = triangle[i][j] + min(dp[i + 1][j], dp[i + 1][j + 1]);
        }
    }
    return dp[0][0];
}

