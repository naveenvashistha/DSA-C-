#include <bits/stdc++.h>

using namespace std;

//orgasmic
//time: O(nlogk)
//space: O(k)
void nearlySorted(vector<int>& arr, int k) {
    // code
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }
    for(int i = k; i < arr.size(); i++)
    {
        pq.push(arr[i]);
        arr[i - k] = pq.top();
        pq.pop();
    }
    for(int i = arr.size() - k; i < arr.size(); i++)
    {
        arr[i] = pq.top();
        pq.pop();
    }
}

int main()
{
}

