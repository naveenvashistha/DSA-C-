#include <bits/stdc++.h>

using namespace std;

//memoization
//time: O(exponentiation)
//space: O(coins.size() * amount)
class Solution {
public:
    int helper(int amount, vector<int>& coins, int ind, vector<vector<int>>& dp)
    {
        if(amount == 0) return 1;
        if(ind == 0){
            if(amount % coins[ind] == 0) return 1;
            return 0;
        }
        if(dp[ind][amount] != -1) return dp[ind][amount];
        int nottake = helper(amount, coins, ind - 1, dp);
        int take = 0;
        if(amount >= coins[ind])
            take = helper(amount - coins[ind], coins, ind, dp);
        return dp[ind][amount] = take + nottake;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        return helper(amount, coins, coins.size() - 1, dp);
    }
};

//tabulation
//time: O(same as above)
//space: O(same as above)
int change(int amount, vector<int>& coins) {
    vector<vector<unsigned long long>> dp(coins.size(), vector<unsigned long long>(amount + 1, 0));
    for(int i = 0; i < coins.size(); i++) dp[i][0] = 1;
    for(int i = 1; i <= amount; i++){
        if(i % coins[0] == 0) dp[0][i] = 1;
    }
    for(int ind = 1; ind < coins.size(); ind++)
    {
        for(int target = 1; target <= amount; target++)
        {
            unsigned long long nottake = dp[ind - 1][target];
            unsigned long long take = 0;
            if(target >= coins[ind]) take = dp[ind][target - coins[ind]];
            dp[ind][target] = nottake + take;
        }
    }
    return dp[coins.size() - 1][amount];
}