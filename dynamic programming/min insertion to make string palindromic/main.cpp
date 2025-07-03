#include <bits/stdc++.h>

using namespace std;

//memoization
//time: O(m*n)
//space: O(m*n)
class Solution {
public:
    int helper(string& s1, string& s2, int ind1, int ind2, vector<vector<int>>& dp)
    {
        if(ind1 < 0 || ind2 < 0) return 0;
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        if(s1[ind1] == s2[ind2])
            return dp[ind1][ind2] = 1 + helper(s1, s2, ind1 - 1, ind2 - 1, dp);
        return dp[ind1][ind2] = max(helper(s1, s2, ind1, ind2 - 1, dp), helper(s1, s2, ind1 - 1, ind2, dp));
    }
    int minInsertions(string s) {
        string temp = s;
        reverse(temp.begin(), temp.end());
        vector<vector<int>> dp(s.length(), vector<int>(s.length(), -1));
        int x = helper(s, temp, s.length() - 1, temp.length() - 1, dp);
        return s.length() - x;
    }
};