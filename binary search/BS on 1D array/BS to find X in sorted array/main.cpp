#include <bits/stdc++.h>

using namespace std;

int search_loop(vector<int>& nums, int target);
int search_recursive(vector<int>& nums, int target);

int main()
{
    vector<int> num {1,2,3,4};
    int n = search_loop(num, 4);
    // int n = search_recursive(num, 4);
    cout << n << endl;
}

//orgasmic
//time: O(logn) if sorted and O(nlogn + logn) if not sorted
//space: O(1)
int search_loop(vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size() - 1;
    int mid;
    while(low <= high)
    {
        mid = (low + high) / 2;
        if(nums[mid] == target) return mid;
        else if(nums[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

//orgasmic
//time: O(logn)
//space: O(logn)
int search_recursive(vector<int>&nums, int low, int high, int target)
{
    int mid = (high + low) / 2;
    if(low > high) return -1;
    if(nums[mid] == target) return mid;
    else if(nums[mid] < target) return search_recursive(nums, mid + 1, high, target);
    else return search_recursive(nums, low, mid - 1, target); 
}