#include <bits/stdc++.h>

using namespace std;

//time: O(nlogn)
//space: O(n)
int minCost(vector<int>& arr) {
    // code here
    priority_queue<int, vector<int>, greater<int>> pq;
    int cost = 0;
    for(int i: arr) pq.push(i);
    while(!pq.empty())
    {
        int r1 = pq.top();
        pq.pop();
        if(!pq.empty()){
            int r2 = pq.top();
            pq.pop();
            pq.push(r1 + r2);
            cost += r1 + r2;
        }
    }
    return cost;
}

int main()
{
}

