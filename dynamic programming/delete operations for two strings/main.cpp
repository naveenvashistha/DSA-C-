#include <bits/stdc++.h>

using namespace std;

//memoization
//time: O(m*n)
//space: O(m*n)
int helper(string& word1, string& word2, int n1, int n2, vector<vector<int>>& dp)
{
    if(n1 < 0 || n2 < 0) return 0;
    if(dp[n1][n2] != -1) return dp[n1][n2];
    if(word1[n1] == word2[n2]) return dp[n1][n2] = 1 + helper(word1, word2, n1 - 1,  n2 - 1, dp);
    return dp[n1][n2] = max(helper(word1, word2, n1 - 1, n2, dp), helper(word1, word2, n1, n2 - 1, dp));
}
int minDistance(string word1, string word2) {
    vector<vector<int>> dp(word1.size(), vector<int>(word2.size(), -1));
    int x = helper(word1, word2, word1.size() - 1, word2.size() - 1, dp);
    return word1.size() + word2.size() - 2 * x;
}