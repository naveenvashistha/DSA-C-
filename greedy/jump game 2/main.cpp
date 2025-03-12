#include <bits/stdc++.h>

using namespace std;

//time: O(nlogn)
//space: O(n)
vector<int> JobSequencing(vector<int> &id, vector<int> &deadline, vector<int> &profit) {
    // code here
    vector<pair<int, int>> dp;
    int max_profit = 0;
    int jobs = 0;
    for(int i = 0; i < deadline.size(); i++)
    dp.push_back({profit[i], deadline[i]});
    sort(dp.begin(), dp.end());
    int maxx = INT_MIN;
    for(int i: deadline) maxx = max(maxx, i);
    vector<int> day(maxx, -1);
    for(int i = dp.size() - 1; i >= 0; i--)
    {
    int j = dp[i].second - 1;
    while(j >= 0 && day[j] != -1) j--;
    if(j >= 0){
    day[j] = 0;
    max_profit += dp[i].first;
    jobs++;
    }
    }
    return {jobs, max_profit};
}

int main()
{
}

