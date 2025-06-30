#include <bits/stdc++.h>

using namespace std;

//memoization
//time: O(n * n)
//space: O(n * n)
int helper(string& s1, string& s2, vector<vector<int>>& dp, int n, int m)
{
	if(n < 0 || m < 0) return 0;
	if(dp[n][m] != -1) return dp[n][m];
	if(s1[n] == s2[m]) return dp[n][m] = 1 + helper(s1, s2, dp, n - 1, m - 1);
	else return dp[n][m] = max(helper(s1, s2, dp, n - 1, m), helper(s1, s2, dp, n, m - 1));
}
int longestPalindromeSubseq(string s) {
	string temp = "";
	for(int i = s.size() - 1; i >= 0; i--) temp += s[i];
	vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
	return helper(s, temp, dp, s.size() - 1, s.size() - 1);
}