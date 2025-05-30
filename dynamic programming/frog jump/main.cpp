#include <bits/stdc++.h>

using namespace std;

//memoization
//time: O(n)
//space: O(n)
int helper(int n, vector<int>& dp, vector<int>& height)
{
    if(n == 0) return 0;
    if(dp[n] != -1) return dp[n];
    int one_jump = INT_MAX, two_jump = INT_MAX;
    one_jump = abs(height[n] - height[n - 1]) + helper(n - 1, dp, height);
    if(n > 1) two_jump = abs(height[n] - height[n - 2]) + helper(n - 2, dp, height);
    return dp[n] = min(one_jump, two_jump);
}
int minCost(vector<int>& height) {
    vector<int> dp(height.size(), -1);
    int ans = helper(height.size() - 1, dp, height);
    return ans;
}

//tabular
//time: O(n)
//space: O(n)
int minCost(vector<int>& height) {
    vector<int> dp(height.size(), -1);
    dp[0] = 0;
    dp[1] = abs(height[1] - height[0]);
    for(int i = 2; i < height.size(); i++){
        dp[i] = min(dp[i - 1] + abs(height[i - 1] - height[i]), dp[i - 2] + abs(height[i - 2] - height[i]));
    }
    return dp[height.size() - 1];
}

//tabular with space optimization
//time: O(n)
//space: O(1)
int minCost(vector<int>& height) {
    if(height.size() == 1) return 0;
    vector<int> dp(height.size(), -1);
    int prev2 = 0;
    int prev1 = abs(height[1] - height[0]);
    int curr;
    for(int i = 2; i < height.size(); i++){
        curr = min(prev1 + abs(height[i - 1] - height[i]), prev2 + abs(height[i - 2] - height[i]));
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}