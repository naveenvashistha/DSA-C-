#include <bits/stdc++.h>

using namespace std;

//memoization
//time: O(m*n)
//space: O(m*n)
class Solution {
public:
    int helper(string& s, string& t, int n1, int n2, vector<vector<int>>& dp)
    {
        if(n2 < 0) return 1;
        if(n1 < 0) return 0;
        if(dp[n1][n2] != -1) return dp[n1][n2];
        if(s[n1] == t[n2]){
            int a = helper(s, t, n1 - 1, n2 - 1, dp);
            int b = helper(s, t, n1 - 1, n2, dp);
            return dp[n1][n2] = a + b;
        }
        else{
            return dp[n1][n2] = helper(s, t, n1 - 1, n2, dp);
        }
    }
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));
        return helper(s, t, s.size() - 1, t.size() - 1, dp);
    }
};


//tabulation
//time: O(m*n)
//space: O(m*n)
typedef unsigned long long ll;
int numDistinct(string s, string t) {
    vector<vector<ll>> dp(s.size() + 1, vector<ll>(t.size() + 1, 0));
    for(int i = 0; i <= s.size(); i++) dp[i][0] = 1;
    for(int i = 1; i <= s.size(); i++)
    {
        for(int j = 1; j <= t.size(); j++)
        {
            if(s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            else dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[s.size()][t.size()];
}