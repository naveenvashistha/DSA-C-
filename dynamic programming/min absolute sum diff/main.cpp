#include <bits/stdc++.h>

using namespace std;

//memoization
//time: O(n * target)
//space: O(n * target)
bool helper(vector<int>& arr, int ind, int target, vector<vector<int>>& dp)
{
	if(target == 0) return true;
	if(ind == 0) return arr[0] == target;
	if(dp[ind][target] != -1) return dp[ind][target];
	bool take = false;
	if(target >= arr[ind]) take = helper(arr, ind - 1, target - arr[ind], dp);
	bool nottake = helper(arr, ind - 1, target, dp);
	return dp[ind][target] = take || nottake;
}
int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.
	int totsum = accumulate(arr.begin(), arr.end(), 0);
	vector<vector<int>> dp(n, vector<int>(totsum + 1, -1));
	for(int i = 0; i <= totsum; i++) helper(arr, n - 1, i, dp);
	int minn = INT_MAX;
	for(int i = 0; i <= totsum; i++){
		if(dp[n - 1][i] == 1){
			int s = totsum - i;
			minn = min(abs(i - s), minn);
		}
	}
	return minn;
}



//tabulation
//time: O(n * target)
//space: O(n * target)
int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.
	int totsum = accumulate(arr.begin(), arr.end(), 0);
	vector<vector<bool>> dp(n, vector<bool>(totsum + 1, false));
	for(int i = 0; i < n; i++) dp[i][0] = true;
	if(arr[0] <= totsum) dp[0][arr[0]] = true;
	for(int i = 1; i < n; i++)
	{
		for(int target = 1; target <= totsum; target++)
		{
			dp[i][target] = dp[i - 1][target] || ((target >= arr[i]) ? dp[i - 1][target - arr[i]] : false);
		}
	}
	int minn = INT_MAX;
	for(int i = 0; i <= totsum; i++)
	{
		if(dp[n - 1][i] == true){
			int s = totsum - i;
			minn = min(minn, abs(i - s));
		}
	}
	return minn;
}