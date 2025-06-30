#include <bits/stdc++.h>

using namespace std;



//tabulation
//time: O(n * m)
//space: O(n * m)
string findLCS(int n, int m,string &s1, string &s2){
	// Write your code here.
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(s1[i - 1] == s2[j - 1])
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	int len = dp[n][m];
	string ans = "";
	while(len > 0)
	{
		if(s1[n - 1] == s2[m - 1]){
			ans.push_back(s1[n - 1]);
			n--;
			m--;
			len--;
		}
		else{
			if(dp[n - 1][m] >= dp[n][m - 1]) n--;
			else m--;
		}
	}
	reverse(ans.begin(), ans.end());
	return ans;	
}