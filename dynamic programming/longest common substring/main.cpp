#include <bits/stdc++.h>

using namespace std;


//tabulation
//time: O(n * m)
//space: O(n * m)
int longestCommonSubstr(string& s1, string& s2) {
	// your code here
	int maxx = 0;
	vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, 0));
	for(int i = 1; i <= s1.length(); i++)
	{
		for(int j = 1; j <= s2.length(); j++)
		{
			if(s1[i - 1] == s2[j - 1]){
				dp[i][j] = 1 + dp[i - 1][j - 1];
				maxx = max(maxx, dp[i][j]);
			}
		}
	}
	return maxx;
}