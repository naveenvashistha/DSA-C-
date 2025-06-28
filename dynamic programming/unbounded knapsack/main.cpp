#include <bits/stdc++.h>

using namespace std;

//memoization
//time: O(n * w)
//space: O(n * w)
int helper(int ind, int w, vector<int>& profit, vector<int>& weight, vector<vector<int>>& dp)
{
    if(w == 0) return 0;
    if(ind == 0){
        if(w >= weight[0]) return profit[0] * (w / weight[0]);
        return 0;
    }
    if(dp[ind][w] != -1) return dp[ind][w];
    int nottake = helper(ind - 1, w, profit, weight, dp);
    int take = 0;
    if(w >= weight[ind]) take = profit[ind] + helper(ind, w - weight[ind], profit, weight, dp);
    return dp[ind][w] = max(take, nottake);
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    // Write Your Code Here.
    vector<vector<int>> dp(n, vector<int>(w + 1, -1));
    return helper(n-1, w, profit, weight, dp);
}

//tabulation
//time: O(same as above)
//space: O(same as above)
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    // Write Your Code Here.
    vector<vector<int>> dp(n, vector<int>(w + 1, 0));
    for(int i = 0; i <= w; i++){
        if(i >= weight[0]) dp[0][i] = profit[0] * (i / weight[0]);
    }
    for(int ind = 1; ind < n; ind++)
    {
        for(int weigh = 1; weigh <= w; weigh++)
        {
            int nottake = dp[ind - 1][weigh];
            int take = 0;
            if(weigh >= weight[ind]) take = profit[ind] + dp[ind][weigh - weight[ind]];
            dp[ind][weigh] = max(take, nottake);
        }
    }
    return dp[n - 1][w];
}