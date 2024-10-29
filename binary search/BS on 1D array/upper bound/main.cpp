#include <bits/stdc++.h>

using namespace std;

int upper_bound(vector<int>& nums, int n, int target);

int main()
{
    vector<int> num {1,2,3,4};
    int n = upper_bound(num, 4, 5);
    cout << n << endl;
}

//brute force would be to apply linear search in sorted array

//orgasmic (striver's)
//time: O(logn) if sorted and O(nlogn + logn) if not sorted
//space: O(1)
int upper_bound(vector<int>& nums, int n, int target) {
    int low = 0;
    int high = n - 1;
    int mid, ans = n;
    while(low <= high)
    {
        mid = (low + high) / 2;
        if(nums[mid] > target){
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return ans;
}