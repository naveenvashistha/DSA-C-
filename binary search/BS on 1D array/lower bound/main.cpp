#include <bits/stdc++.h>

using namespace std;

int lower_bound1(vector<int>& nums, int n, int target);
int lower_bound2(vector<int>& nums, int n, int target);

int main()
{
    vector<int> num {1,2,3,4};
    int n = lower_bound1(num, 4, 5);
    // int n = lower_bound2(num, 4, 5);
    cout << n << endl;
}

//brute force would be to apply linear search in sorted array

//orgasmic (my approach)
//time: O(logn) if sorted and O(nlogn + logn) if not sorted
//space: O(1)
int lower_bound1(vector<int>& nums, int n, int target) {
    int low = 0;
    int high = n - 1;
    int mid;
    while(low <= high)
    {
        if(nums[low] >= target) return low;
        else if(nums[high] < target) return high + 1;
        mid = (low + high) / 2;
        if(nums[mid] == target) return mid;
        else if(nums[mid] > target) high = mid - 1;
        else low = mid + 1;
    }
}

//orgasmic (striver's)
//time: O(logn) if sorted and O(nlogn + logn) if not sorted
//space: O(1)
int lower_bound2(vector<int>& nums, int n, int target) {
    int low = 0;
    int high = n - 1;
    int mid, ans = n;
    while(low <= high)
    {
        mid = (low + high) / 2;
        if(nums[mid] >= target){
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return mid;
}