#include <bits/stdc++.h>

using namespace std;

//memoization
//time: O(n * target)
//space: O(n * target)
class Solution {
public:
    int helper(vector<int>& nums, int target, vector<vector<int>>& dp, int ind)
    {
        if(ind == 0){
            if(target == 0 && nums[0] == 0) return 2; 
            if(target == 0 || target == nums[0]) return 1;
            return 0;
        }
        if(dp[ind][target] != -1) return dp[ind][target];
        int nottake = helper(nums, target, dp, ind - 1);
        int take = 0;
        if(target >= nums[ind])
            take = helper(nums, target - nums[ind], dp, ind - 1);
        return dp[ind][target] = take + nottake;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int totsum = 0;
        for(int i: nums) totsum += i;
        if(totsum < abs(target) || (totsum - target) % 2 != 0) return 0;
        int t = (totsum - target) / 2;
        vector<vector<int>> dp(nums.size(), vector<int>(t + 1, -1));
        return helper(nums, t, dp, nums.size() - 1);
    }
};


