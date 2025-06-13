#include <bits/stdc++.h>

using namespace std;

//memoization
//time: O(n)
//space: O(n)
class Solution {
  public:
    int helper(vector<vector<int>>& dp, vector<vector<int>>& arr, int day, int last_task)
    {
        if(dp[day][last_task] != -1) return dp[day][last_task];
        int maxi = 0;
        if(day == arr.size() - 1){
            for(int i = 0; i < 3; i++)
            {
                if(i != last_task){
                    maxi = max(arr[day][i], maxi);
                }
            }
            return dp[day][last_task] = maxi;
        }
        for(int i = 0; i < 3; i++)
        {
            if(i != last_task)
            {
                int points = arr[day][i] + helper(dp, arr, day + 1, i);
                maxi = max(maxi, points);
            }
        }
        return dp[day][last_task] = maxi;
    }
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        vector<vector<int>> dp(arr.size(), vector<int>(4, -1));
        return helper(dp, arr, 0, 3);
    }
};

//tabulation
//time: O(n)
//space: O(n)
class Solution {
  public:
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        vector<vector<int>> dp(arr.size(), vector<int>(4, 0));
        dp[0][0] = max(arr[0][1], arr[0][2]);
        dp[0][1] = max(arr[0][0], arr[0][2]);
        dp[0][2] = max(arr[0][0], arr[0][1]);
        for(int day = 1; day < arr.size(); day++)
        {
            for(int last = 0; last < 4; last++)
            {
                dp[day][last] = 0;
                for(int task = 0; task < 3; task++)
                {
                    if(last != task){
                        dp[day][last] = max(arr[day][task] + dp[day - 1][task], dp[day][last]);
                    }
                }
            }
        }
        return dp[arr.size() - 1][3];
    }
};

//space optimization
//time: O(n)
//space: O(1)
class Solution {
  public:
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        vector<int> prev(4, 0);
        prev[0] = max(arr[0][1], arr[0][2]);
        prev[1] = max(arr[0][0], arr[0][2]);
        prev[2] = max(arr[0][0], arr[0][1]);
        for(int day = 1; day < arr.size(); day++)
        {
            vector<int> temp(4, 0);
            for(int last = 0; last < 4; last++)
            {
                for(int task = 0; task < 3; task++)
                {
                    if(last != task){
                        temp[last] = max(arr[day][task] + prev[task], temp[last]);
                    }
                }
            }
            prev = temp;
        }
        return prev[3];
    }
};

