#include <bits/stdc++.h>

using namespace std;

class KthLargest {
public:
    int ka;
    priority_queue<int, vector<int>, greater<int>> pq;
    //time: O(nlogk)
    KthLargest(int k, vector<int>& nums) {
        ka = k;
        for(int i: nums)
        {
            if(pq.size() < ka) pq.push(i);
            else if(i > pq.top())
            {
                pq.pop();
                pq.push(i);
            }
        }
    }
    //time: O(logk)
    int add(int val) {
        if(pq.size() < ka) pq.push(val);
        else if(val > pq.top())
        {
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }
};