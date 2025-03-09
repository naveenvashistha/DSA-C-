#include <bits/stdc++.h>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b)
{
    double r1 = (double)a.first / a.second;
    double r2 = (double)b.first / b.second;
    return r1 > r2;
}
// Function to get the maximum total value in the knapsack.
//time: O(nlogn)
//space: O(n)
double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
    // Your code here
    double ans = 0;
    vector<pair<int, int>> wv;
    for(int i = 0; i < val.size(); i++)
        wv.push_back({val[i], wt[i]});
    sort(wv.begin(), wv.end(), comp);
    int i = 0;
    while(capacity != 0 && i < wv.size())
    {
        if(capacity > wv[i].second)
        {
            ans += wv[i].first;
            capacity -= wv[i].second;
        }
        else
        {
            ans += ((double)wv[i].first / wv[i].second) * capacity;
            capacity = 0;
        }
        i++;
    }
    return ans;
}
int main()
{
}

