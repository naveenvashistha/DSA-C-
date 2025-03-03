#include <bits/stdc++.h>

using namespace std;

//orgasmic
//time: O(n) for avg and O(n^2) for worst
//space: O(1)
int quick(vector<int>& nums, int k, int pivot, int length)
{
    int low = pivot + 1;
    int high = length;
    while(low <= high)
    {
        if(nums[pivot] < nums[low] && nums[pivot] > nums[high]){
            swap(nums[low], nums[high]);
            low++;
            high--;
        }
        if(nums[low] <= nums[pivot])
        {
            low++;
        }
        if(nums[high] >= nums[pivot])
        {
            high--;
        }
    }
    swap(nums[high], nums[pivot]);
    if(high < k)
        return quick(nums, k, high + 1, length);
    else if(high > k)
        return quick(nums, k, pivot, high - 1);
    return nums[high];
}    
int findKthLargest(vector<int>& nums, int k) {
    return quick(nums, nums.size() - k, 0, nums.size() - 1);
}

//better
//time: O(nlogn)
//space: O(n)
int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int> pq;
    for(int i = 0; i < nums.size(); i++)
    {
        pq.push(nums[i]);
    }
    int j = k - 1;
    while(j != 0)
    {
        pq.pop();
        j--;
    }
    return pq.top();
}
int main()
{
}

