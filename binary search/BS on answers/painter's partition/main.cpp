#include <bits/stdc++.h>

using namespace std;

int painters1(vector<int>& arr, int k);
int painters2(vector<int>& arr, int k);
int isAllocationPossible(vector<int>& arr,  int max_pages, int size);

int main()
{
    vector<int> nums = {2,3,4,7,11};
    int n = painters1(nums, 5);
    cout << n << endl;
}

//brute
//time: O(n * (sum - max))
//space: O(1)
int painters1(vector<int>& arr, int k)
{
    int n = arr.size();
    if(k > n) return -1;
    int max_time = INT_MIN;
    long long sum = 0;
    for(int i = 0; i < n; i++)
    {
        max_time = max(max_time, arr[i]);
        sum += arr[i];
    }
    for(int i = max_time; i <= sum; i++)
    {
        int res = isAllocationPossible(arr, i, n);
        if(res <= k)
            return i;
    }
    return max_time; 
}

//orgasmic
//time: O(n * log(sum - max))
//sapce: O(1)
int painters2(vector<int>& arr, int k)
{
    int n = arr.size();
    int min_max_time = INT_MAX;
    int max_time = INT_MIN;
    long long sum = 0;
    for(int i = 0; i < n; i++)
    {
        max_time = max(max_time, arr[i]);
        sum += arr[i];
    }
    int low = max_time, high = sum, mid;
    while(low <= high)
    {
        mid = (low + high) / 2;
        int res = isAllocationPossible(arr, mid, n);
        if(res <= k)
        {
            min_max_time = min(min_max_time, mid);
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return min_max_time;
}

int isAllocationPossible(vector<int>& arr, int max_time, int size)
{
    long long sum = 0;
    int subarray = 1;
    for(int i = 0; i < size; i++)
    {
        if(sum + arr[i] <= max_time)
        {
            sum += arr[i];
        }
        else
        {
            subarray++;
            sum = arr[i];
        }
    }
    return subarray;
}