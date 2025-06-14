#include <bits/stdc++.h>

using namespace std;

//memoization
//time: O(m*n)
//space: O(m*n)
class Solution {
public:
    int helper(int r, int c, vector<vector<int>>& matrix, vector<vector<int>>& dp)
    {
        if(dp[r][c] != -1) return dp[r][c];
        if(r == matrix.size() - 1) return dp[r][c] = matrix[r][c];

        int left = INT_MAX, down = INT_MAX, right = INT_MAX;
        if(c - 1 >= 0) left = helper(r + 1, c - 1, matrix, dp);
        if(c + 1 < matrix[0].size()) right = helper(r + 1, c + 1, matrix, dp);
        down = helper(r + 1, c, matrix, dp);

        return dp[r][c] = matrix[r][c] + min(left, min(right, down));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int minn = INT_MAX;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));
        for(int i = 0; i < matrix[0].size(); i++)
        {
            minn = min(minn, helper(0, i, matrix, dp));
        }
        return minn;
    }
};

//tabulation
//time: same as above
//space: same as above
int minFallingPathSum(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));
    for(int i = m - 1; i >= 0; i--)
    {
        for(int j = n - 1; j >= 0; j--)
        {
            if(i == m - 1){
                dp[i][j] = matrix[i][j];
                continue;
            }
            int left = INT_MAX, down = INT_MAX, right = INT_MAX;
            if(j - 1 >= 0) left = dp[i + 1][j - 1];
            if(j + 1 < n) right = dp[i + 1][j + 1];
            down = dp[i + 1][j];

            dp[i][j] = matrix[i][j] + min(left, min(down, right));
        }
    }
    int minn = INT_MAX;
    for(int i = 0; i < n; i++) minn = min(minn, dp[0][i]);
    return minn;
}

