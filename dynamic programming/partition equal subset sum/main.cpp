#include <bits/stdc++.h>

using namespace std;

//memoization
//time: O(n * target)
//space: O(n * target)
class Solution {
public:
    bool helper(vector<int>& nums, int ind, int target, vector<vector<int>>& dp)
    {
        if(target == 0) return true;
        if(ind == 0) return nums[0] == target;
        if(dp[ind][target] != -1) return dp[ind][target];
        bool take = false;
        if(target >= nums[ind]) take = helper(nums, ind - 1, target - nums[ind], dp);
        bool nottake = helper(nums, ind - 1, target, dp);
        return dp[ind][target] = take || nottake;
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 != 0) return false;
        vector<vector<int>> dp(nums.size(), vector<int>(sum / 2 + 1, -1));
        return helper(nums, nums.size() - 1, sum / 2, dp);
    }
};


