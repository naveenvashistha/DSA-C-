#include <bits/stdc++.h>

using namespace std;

//memoization
//time: O(n * k)
//space: O(n)
class Solution {
  public:
    int helper(vector<int>& arr, vector<int>& dp, int n, int k)
    {
        if(n == 0) return 0;
        if(dp[n] != -1) return dp[n];
        int jump_cost = INT_MAX;
        for(int i = 1; i <= k; i++)
        {
            if(n - i >= 0)
                jump_cost = min(jump_cost, abs(arr[n] - arr[n - i]) + helper(arr, dp, n - i, k));
        }
        return dp[n] = jump_cost;
    }
    int minimizeCost(int k, vector<int>& arr) {
        // Code here
        vector<int> dp(arr.size(), -1);
        helper(arr, dp, arr.size() - 1, k);
        return dp[arr.size() - 1];
    }
};

//tabular
//time: O(n * k)
//space: O(n)
int minimizeCost(int k, vector<int>& arr) {
    // Code here
    vector<int> dp(arr.size(), INT_MAX);
    dp[0] = 0;
    for(int i = 1; i < arr.size(); i++)
    {
        for(int j = 1; j <= k; j++)
        {
            if(i - j >= 0) dp[i] = min(dp[i], abs(arr[i] - arr[i - j]) + dp[i - j]);
        }
    }
    return dp[arr.size() - 1];
}
