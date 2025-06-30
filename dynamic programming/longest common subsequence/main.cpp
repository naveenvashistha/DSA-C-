#include <bits/stdc++.h>

using namespace std;

//memoization
//time: O(n * m)
//space: O(n * m)
class Solution {
public:
    int helper(string& text1, string& text2, int ind1, int ind2, vector<vector<int>>& dp)
    {
        if(ind1 < 0 || ind2 < 0) return 0;
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        if(text1[ind1] == text2[ind2]) return dp[ind1][ind2] = 1 + helper(text1, text2, ind1 - 1, ind2 - 1, dp);
        return dp[ind1][ind2] = max(helper(text1, text2, ind1 - 1, ind2, dp), helper(text1, text2, ind1, ind2 - 1, dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.length(), vector<int>(text2.length(), -1));
        return helper(text1, text2, text1.length() - 1, text2.length() - 1, dp);
    }
};

//tabulation
//time: O(same as above)
//space: O(same as above)
int longestCommonSubsequence(string text1, string text2) {
	vector<vector<int>> dp(text1.length() + 1, vector<int>(text2.length() + 1, 0));
	for(int ind1 = 1; ind1 <= text1.length(); ind1++)
	{
		for(int ind2 = 1; ind2 <= text2.length(); ind2++)
		{
			if(text1[ind1 - 1] == text2[ind2 - 1]){
				dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
			}
			else{
				dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
			}
		}
	}
	return dp[text1.length()][text2.length()];
}