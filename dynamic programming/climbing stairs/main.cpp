#include <bits/stdc++.h>

using namespace std;

//memoization
//time: O(n)
//space: O(n)
int helper(int n, vector<int>& dp)
{
    if(n == 0) return 1;
    if(n < 0) return 0;
    if(dp[n] != -1) return dp[n];
    return dp[n] = helper(n - 1, dp) + helper(n - 2, dp);
}
int climbStairs(int n) {
    vector<int> dp(n + 1, -1);
    int ans = helper(n, dp);
    return ans;
}

//tabular
//time: O(n)
//space: O(n)
int climbStairs(int n) {
    vector<int> dp(n + 1, -1);
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i <= n; i++){
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

//tabular with space optimization
//time: O(n)
//space: O(1)
int climbStairs(int n) {
    int ans = 1;
    int prev1 = 1;
    int prev2 = 1;
    for(int i = 2; i <= n; i++){
        ans = prev1 + prev2;
        prev2 = prev1;
        prev1 = ans;
    }
    return ans;
}