#include <bits/stdc++.h>

using namespace std;

//memoization
//time: O(m*n)
//space: O(m*n)
class Solution {
public:
    int helper(int r, int c, int m, int n, vector<vector<int>> & dp)
    {
        if(r == m - 1 && c == n - 1) return 1;
        if(dp[r][c] != -1) return dp[r][c];
        int a = 0, b = 0;
        if(r + 1 < m) a = helper(r + 1, c, m, n, dp);
        if(c + 1 < n) b = helper(r, c + 1, m, n, dp);
        return dp[r][c] = a + b;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(0, 0, m, n, dp);
    }
};


//space optimization
//time: O(m*n)
//space: O(m*n)
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        for(int i = m - 1; i >= 0; i--)
        {
            for(int j = n - 1; j >= 0; j--)
            {
                int up = 0, left = 0; 
                if(i == m - 1 && j == n - 1){
                    dp[i][j] = 1;
                    continue;
                }
                if(i + 1 < m) up = dp[i + 1][j];
                if(j + 1 < n) left = dp[i][j + 1];
                dp[i][j] = up + left; 
            }
        }
        return dp[0][0];
    }
};