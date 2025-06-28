#include <bits/stdc++.h>

using namespace std;

//memoization
//time: O(n * n)
//space: O(n * n)
int helper(vector<int>& price, int ind, int len, vector<vector<int>>& dp)
{
	if(len == 0) return 0;
	if(ind == 0){
		return len * price[ind];
	}
	if(dp[ind][len] != -1) return dp[ind][len];
	int nottake = helper(price, ind - 1, len, dp);
	int take = 0;
	if(len >= ind + 1) take = price[ind] + helper(price, ind, len - (ind + 1), dp);
	return dp[ind][len] = max(take, nottake);
}
int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	vector<vector<int>> dp(n, vector<int>(n + 1, -1));
	return helper(price, n - 1, n, dp);
}

//tabulation
//time: O(same as above)
//space: O(same as above)
int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	vector<vector<int>> dp(n, vector<int>(n + 1, 0));
	for(int i = 1; i <= n; i++) dp[0][i] = i * price[0];
	for(int ind = 1; ind < n; ind++)
	{
		for(int len = 1; len <= n; len++)
		{
			int nottake = dp[ind - 1][len];
			int take = 0;
			if(len >= ind + 1) take = price[ind] + dp[ind][len - (ind + 1)];
			dp[ind][len] = max(nottake, take);
		}
	}
	return dp[n - 1][n];
}