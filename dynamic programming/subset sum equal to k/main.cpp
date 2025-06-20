#include <bits/stdc++.h>

using namespace std;

//memoization
//time: O(n * target)
//space: O(n * target)
bool helper(vector<int>& arr, vector<vector<int>>& dp, int target, int ind)
{
    if(target == 0) return true;
    if(ind == 0) return arr[0] == target;
    if(dp[ind][target] != -1) return dp[ind][target];
    bool nottake = helper(arr, dp, target, ind - 1);
    bool take = false;
    if(target >= arr[ind]) take = helper(arr, dp, target - arr[ind], ind - 1);
    return dp[ind][target] = (nottake || take);    
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int>> dp(1e3 + 1, vector<int>(1e3 + 1, -1));
    return helper(arr, dp, k, n - 1);
}


//tabulation
//time: O(n * target)
//space: O(n * target)
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));
    for(int i = 0; i < n; i++) dp[i][0] = true;
    if(arr[0] <= k) dp[0][arr[0]] = true;
    for(int i = 1; i < n; i++)
    {
        for(int target = 1; target <= k; target++)
        {
            dp[i][target] = dp[i - 1][target] || ((target >= arr[i]) ? dp[i - 1][target - arr[i]] : false);
        }
    }
    return dp[n - 1][k];
}