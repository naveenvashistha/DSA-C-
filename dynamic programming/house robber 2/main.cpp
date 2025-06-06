#include <bits/stdc++.h>

using namespace std;

//memoization
//time: O(n)
//space: O(n)
int helper(vector<int>& nums, vector<int>& dp, int ind, int min_index)
{
    if(ind == min_index) return nums[min_index];
    if(ind < min_index) return 0;
    if(dp[ind] != -1) return dp[ind];
    int one = helper(nums, dp, ind - 1, min_index);
    int two = nums[ind] + helper(nums, dp, ind - 2, min_index);
    return dp[ind] = max(one, two); 
}
int rob(vector<int>& nums) {
    if(nums.size() == 1) return nums[0];
    vector<int> dp1(nums.size(), -1);
    vector<int> dp2(nums.size(), -1);
    return max(helper(nums, dp1, nums.size() - 1, 1), helper(nums, dp2, nums.size() - 2, 0));
}

//space optimization
//time: O(n)
//space: O(1)
int rob(vector<int> nums) {
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

int robber(vector<int> nums)
{
    vector<int> temp1;
    vector<int> temp2;
    if(nums.size() == 1) return nums[0];
    for(int i = 0; i < nums.size(); i++)
    {
        if(i != 0) temp2.push_back(nums[i]);
        if(i != nums.size() - 1) temp1.push_back(nums[i]);
    }
    return max(rob(temp1), rob(temp2));
}