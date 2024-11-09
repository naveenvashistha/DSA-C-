#include <bits/stdc++.h>

using namespace std;

int split1(vector<int>& arr, int k);
int split2(vector<int>& arr, int k);
int isAllocationPossible(vector<int>& arr,  int max_pages, int size);

int main()
{
    vector<int> nums = {2,3,4,7,11};
    int n = split1(nums, 5);
    cout << n << endl;
}

//brute
//time: O(n * (sum - max))
//space: O(1)
int split1(vector<int>& arr, int k)
{
    int n = arr.size();
    if(k > n) return -1;
    int max_sum = INT_MIN;
    long long sum = 0;
    for(int i = 0; i < n; i++)
    {
        max_sum = max(max_sum, arr[i]);
        sum += arr[i];
    }
    for(int i = max_sum; i <= sum; i++)
    {
        int res = isAllocationPossible(arr, i, n);
        if(res == k)
            return i;
    }
    return max_sum; //you cant get more less min value of max pages than this
}

//orgasmic
//time: O(n * log(sum - max))
//sapce: O(1)
int pages2(vector<int>& arr, int k)
{
    int n = arr.size();
    if(k > n) return -1;
    int min_max_sum = INT_MAX;
    int max_sum = INT_MIN;
    long long sum = 0;
    for(int i = 0; i < n; i++)
    {
        max_sum = max(max_sum, arr[i]);
        sum += arr[i];
    }
    int low = max_sum, high = sum, mid;
    while(low <= high)
    {
        mid = (low + high) / 2;
        int res = isAllocationPossible(arr, mid, n);
        if(res == k)
        {
            min_max_sum = min(min_max_sum, mid);
            high = mid - 1;
        }
        else if(res < k) high = mid - 1;
        else low = mid + 1;
    }
    return min_max_sum == INT_MAX ? max_sum : min_max_sum;
}

int isAllocationPossible(vector<int>& arr, int max_sum, int size)
{
    long long sum = 0;
    int subarray = 1;
    for(int i = 0; i < size; i++)
    {
        if(sum + arr[i] <= max_sum)
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