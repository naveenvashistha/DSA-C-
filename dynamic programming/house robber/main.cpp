#include <bits/stdc++.h>

using namespace std;

//memoization
//time: O(n)
//space: O(n)
class Solution {
public:
    int helper(vector<int>& nums, vector<int>& dp, int ind)
    {
        if(ind == 0){
            return nums[0];
        }
        if(ind < 0) return 0;
        if(dp[ind] != -1) return dp[ind];
        int one = helper(nums, dp, ind - 1);
        int two = nums[ind] + helper(nums, dp, ind - 2);
        return dp[ind] = max(one, two);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return helper(nums, dp, nums.size() - 1);
    }
};

//tabular
//time: O(n)
//space: O(n)
int rob(vector<int>& nums) {
    vector<int> dp(nums.size(), -1);
    dp[0] = nums[0];
    for(int i = 1; i < nums.size(); i++)
    {
        dp[i] = dp[i - 1];
        if(i > 1) dp[i] = max(dp[i], nums[i] + dp[i - 2]);
        else dp[i] = max(dp[i], nums[i]);
    }
    return dp[nums.size() - 1];
}

//space optimization
//time: O(n)
//space: O(1)
int rob(vector<int>& nums) {
    int prev1 = nums[0], prev2 = 0;
    int sum = prev1;
    for(int i = 1; i < nums.size(); i++)
    {
        sum = max(nums[i] + prev2, prev1);
        prev2 = prev1;
        prev1 = sum;
    }
    return sum;
}