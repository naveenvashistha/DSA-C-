#include <bits/stdc++.h>

using namespace std;

//memoization
//time: O(exponential)
//space: O(coins array size * amount)
class Solution {
public:
    int helper(vector<int>& coins, int amount, int ind, vector<vector<int>>& dp)
    {
        if(ind == 0){
            if(amount % coins[0] == 0) return amount / coins[0];
            return 1e9;
        }
        if(dp[ind][amount] != -1) return dp[ind][amount];
        int nottake = helper(coins, amount, ind - 1, dp);
        int take = INT_MAX;
        if(amount >= coins[ind]) take = 1 + helper(coins, amount - coins[ind], ind, dp);
        return dp[ind][amount] = min(nottake, take);
    }
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        int ans = helper(coins, amount, coins.size() - 1, dp);
        if(ans >= 1e9) return -1;
        return ans;
    }
};


//space optimization
//time: O(exponentiation)
//space: O(same as above)
int coinChange(vector<int>& coins, int amount) {
    if(amount == 0) return 0;
    vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, 0));
    for(int i = 0; i <= amount; i++){
        if(i % coins[0] == 0) dp[0][i] = i / coins[0];
        else dp[0][i] = 1e9;
    }
    for(int ind = 1; ind < coins.size(); ind++)
    {
        for(int T = 0; T <= amount; T++)
        {
            int nottake = dp[ind - 1][T];
            int take = 1e9;
            if(T >= coins[ind]) take = 1 + dp[ind][T - coins[ind]];
            dp[ind][T] = min(take, nottake); 
        }
    }
    if(dp[coins.size() - 1][amount] >= 1e9) return -1;
    return dp[coins.size() - 1][amount];
}