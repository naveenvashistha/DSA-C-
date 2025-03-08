#include <bits/stdc++.h>

using namespace std;
class MedianFinder {
public:
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    MedianFinder() {
        
    }
    //tiem: O(logn)
    void addNum(int num) {
        if(max_heap.size() == 0 && max_heap.size() == min_heap.size())
            max_heap.push(num);
        else if(num < max_heap.top())
            max_heap.push(num);
        else
            min_heap.push(num);
        if(abs((double)max_heap.size() - min_heap.size()) >= 2)
        {
            if(max_heap.size() > min_heap.size())
            {
                int temp = max_heap.top();
                max_heap.pop();
                min_heap.push(temp);
            }
            else
            {
                int temp = min_heap.top();
                min_heap.pop();
                max_heap.push(temp);
            }
        }
    }
    //time: O(1)
    double findMedian() {
        if(max_heap.size() == min_heap.size())
            return (min_heap.top() + max_heap.top()) / 2.0; 
        else if(max_heap.size() > min_heap.size())
            return max_heap.top();
        return min_heap.top();
    }
};
    
int main()
{
}

