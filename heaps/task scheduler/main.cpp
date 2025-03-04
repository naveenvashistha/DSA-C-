#include <bits/stdc++.h>

using namespace std;

//time: O(t) + O(26log26) + O(tlog26) = O(t)
//space: O(t)
int leastInterval(vector<char>& tasks, int n) {
    unordered_map<int, int> mp;
    priority_queue<int> pq;
    int time = 0;
    for(int i: tasks) mp[i]++;
    for(auto i: mp) pq.push(i.second);
    while(!pq.empty())
    {
        vector<int> left;
        for(int i = 0; i < n + 1; i++)
        {
            if(!pq.empty()){
                int t = pq.top();
                pq.pop();
                t--;
                if(t != 0) left.push_back(t);
            }
            if(!pq.empty() || left.size() != 0) time++;
        }
        for(int i: left) pq.push(i);
    }
    return time + 1;
}

int main()
{
}

