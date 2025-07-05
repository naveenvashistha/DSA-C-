#include <bits/stdc++.h>

using namespace std;

//memoization
//time: O(m*n)
//space: O(m*n)
class Solution {
public:
    bool isAllStars(string& p, int n2)
    {
        for(int i = n2; i >= 0; i--){
            if(p[i] != '*') return false;
        }
        return true;
    }
    int helper(string& s, string& p, int n1, int n2, vector<vector<int>>& dp)
    {
        if(n2 < 0 && n1 < 0) return 1;
        if(n1 >= 0 && n2 < 0) return 0;
        if(n1 < 0 && n2 >= 0) return isAllStars(p, n2);
        if(dp[n1][n2] != -1) return dp[n1][n2];
        if(s[n1] == p[n2] || p[n2] == '?') return dp[n1][n2] = helper(s, p, n1 - 1, n2 - 1, dp);
        else{
            if(p[n2] == '*'){
                return dp[n1][n2] = helper(s, p, n1 - 1, n2, dp) || helper(s, p, n1, n2 - 1, dp);
            }
            return dp[n1][n2] = 0;
        }
    }
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size(), vector<int>(p.size(), -1));
        return helper(s, p, s.size() - 1, p.size() - 1, dp);
    }
};


//tabulation
//time: O(m*n)
//space: O(m*n)
bool isMatch(string s, string p) {
    vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
    int star = p.size();
    for(int i = 0; i < p.size(); i++){
        if(p[i] != '*'){
            star = i;
            break;
        }
    }
    for(int i = 0; i <= star; i++) dp[0][i] = true;
    for(int i = 1; i <= s.size(); i++)
    {
        for(int j = 1; j <= p.size(); j++)
        {
            if(s[i - 1] == p[j - 1] || p[j - 1] == '?')
                dp[i][j] = dp[i - 1][j - 1];
            else if(p[j - 1] == '*')
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
        }
    }
    return dp[s.size()][p.size()];
}