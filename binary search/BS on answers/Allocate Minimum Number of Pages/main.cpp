#include <bits/stdc++.h>

using namespace std;

int pages1(vector<int>& arr, int n, int m);
int pages2(vector<int>& arr, int n, int m);
int isAllocationPossible(vector<int>& arr,  int max_pages, int size);

int main()
{
    vector<int> nums = {2,3,4,7,11};
    int n = pages1(nums, nums.size(), 5);
    cout << n << endl;
}

//brute
//time: O(n * (sum - max))
//space: O(1)
int pages1(vector<int>& arr, int n, int m)
{
    if(m > n) return -1;
    int max_pages = INT_MIN;
    long long sum = 0;
    for(int i = 0; i < n; i++)
    {
        max_pages = max(max_pages, arr[i]);
        sum += arr[i];
    }
    for(int i = max_pages; i <= sum; i++)
    {
        int res = isAllocationPossible(arr, i, n);
        if(res == m)
            return i;
    }
    return max_pages; //you cant get more less min value of max pages than this
}

//orgasmic
//time: O(n * log(sum - max))
//sapce: O(1)
int pages2(vector<int>& arr, int n, int m)
{
    if(m > n) return -1;
    int min_max_pages = INT_MAX;
    int max_pages = INT_MIN;
    long long sum = 0;
    for(int i = 0; i < n; i++)
    {
        max_pages = max(max_pages, arr[i]);
        sum += arr[i];
    }
    int low = max_pages, high = sum, mid;
    while(low <= high)
    {
        mid = (low + high) / 2;
        int res = isAllocationPossible(arr, mid, n);
        if(res == m)
        {
            min_max_pages = min(min_max_pages, mid);
            high = mid - 1;
        }
        else if(res < m) high = mid - 1;
        else low = mid + 1;
    }
    return min_max_pages == INT_MAX ? max_pages : min_max_pages;
}

int isAllocationPossible(vector<int>& arr, int max_pages, int size)
{
    long long noOfPages = 0;
    int students = 1;
    for(int i = 0; i < size; i++)
    {
        if(noOfPages + arr[i] <= max_pages)
        {
            noOfPages += arr[i];
        }
        else
        {
            students++;
            noOfPages = arr[i];
        }
    }
    return students;
}