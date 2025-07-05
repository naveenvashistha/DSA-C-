#include <bits/stdc++.h>

using namespace std;

//memoization
//time: O(m*n)
//space: O(m*n)
class Solution {
public:
    int helper(string& s1, string& s2, int n1, int n2, vector<vector<int>>& dp)
    {
        if(n1 < 0) return n2 + 1;
        if(n2 < 0) return n1 + 1;
        if(dp[n1][n2] != -1) return dp[n1][n2];
        if(s1[n1] == s2[n2]) return dp[n1][n2] = helper(s1, s2, n1 - 1, n2 - 1, dp);
        else{
            int a = helper(s1, s2, n1 - 1, n2 - 1, dp); // replace
            int b = helper(s1, s2, n1, n2 - 1, dp); // insert
            int c = helper(s1, s2, n1 - 1, n2, dp); // delete
            return dp[n1][n2] = 1 + min(a, min(b, c)); 
        }
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size(), vector<int>(word2.size(), -1));
        return helper(word1, word2, word1.size() - 1, word2.size() - 1, dp);
    }
};


//tabulation
//time: O(m*n)
//space: O(m*n)
int minDistance(string word1, string word2) {
    vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
    for(int i = 0; i <= word1.size(); i++) dp[i][0] = i;
    for(int i = 0; i <= word2.size(); i++) dp[0][i] = i;
    for(int i = 1; i <= word1.size(); i++)
    {
        for(int j = 1; j <= word2.size(); j++)
        {
            if(word1[i - 1] == word2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else{
                dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1]));
            }
        }
    }
    return dp[word1.size()][word2.size()];
}