#include <bits/stdc++.h>

using namespace std;

//orgasmic
//time: O(100000xn)
//space: O(100000xn)
int minimumMultiplications(vector<int>& arr, int start, int end) {
    // code here
    if(start == end) return 0;
    queue<pair<int, int>> q;
    q.push({start, 0});
    const int mod = 1e5;
    vector<int> dist(100000, INT_MAX);
    while(!q.empty())
    {
        int node = q.front().first;
        int steps = q.front().second;
        q.pop();
        for(int i: arr)
        {
            int s = (node * i) % mod;
            if(s == end) return steps + 1;
            else if(steps + 1 < dist[s]){
                dist[s] = steps + 1;
                q.push({s, steps + 1});
            }
        }
    }
    return -1;
}