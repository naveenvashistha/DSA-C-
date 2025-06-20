#include <bits/stdc++.h>

using namespace std;

//memoization
//time: O(n * target)
//space: O(n * target)
int mod = 1e9 + 7;
int helper(vector<int>& arr, vector<vector<int>>& dp, int target, int ind)
{
	if(ind == 0){
		if(target == 0 && arr[0] == 0) return 2;
		if(target == 0 || arr[0] == target) return 1;
		return 0;
	}
	if(dp[ind][target] != -1) return dp[ind][target]; 
	int take = 0;
	if(target >= arr[ind]) take = helper(arr, dp, target - arr[ind], ind - 1);
	int nottake = helper(arr, dp, target, ind - 1);
	return dp[ind][target] = (take + nottake) % mod;
}
int findWays(vector<int>& arr, int k)
{
	// Write your code here.
	vector<vector<int>> dp(arr.size(), vector<int>(k + 1, -1));
	return helper(arr, dp, k, arr.size() - 1);
}


//tabulation
//time: O(n * target)
//space: O(n * target)
int findWays(vector<int>& arr, int k)
{
	// Write your code here.
	vector<vector<int>> dp(arr.size(), vector<int>(k + 1, 0));
	if(arr[0] == 0) dp[0][0] = 2;
	else dp[0][0] = 1;
	if(arr[0] != 0 && arr[0] <= k) dp[0][arr[0]] = 1;
	for(int i = 1; i < arr.size(); i++)
	{
		for(int target = 0; target <= k; target++)
		{
			dp[i][target] = (dp[i - 1][target] + (arr[i] <= target ? dp[i - 1][target - arr[i]] : 0)) % mod;
		}
	}
	return dp[arr.size() - 1][k];
}