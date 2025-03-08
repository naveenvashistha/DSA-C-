#include <bits/stdc++.h>

using namespace std;

//time: O(nlogn)
//space: O(n)
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    priority_queue<pair<int, int>> pq; 
    vector<int> ans;
    for(int i: nums)
        mp[i]++;
    for(auto i: mp)
        pq.push({i.second, i.first});
    for(int i = 0; i < k; i++)
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    return ans;
}
    
int main()
{
}

