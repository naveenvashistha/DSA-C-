#include <bits/stdc++.h>

using namespace std;

int divisor1(vector<int>& nums, int threshold);
int divisor2(vector<int>& nums, int threshold);
long long calculateSum(vector<int>& nums, int divisor, int size);

int main()
{
    vector<int> piles = {25, 12, 8, 14, 19};
    int n = divisor1(piles, 5);
    cout << n << endl;
}

//brute force
//time: O(n) + O(n*maxx)
//space: O(1)
int divisor1(vector<int>& nums, int threshold)
{
    int n = nums.size();
    int maxx = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        maxx = max(maxx, nums[i]);
    }
    for(int i = 1; i <= maxx; i++)
    {
        long long k = calculateSum(nums, i, n);
        if(k <= threshold)
        {
            return i;
        }
    }
    return -1;
}

long long calculateSum(vector<int>& nums, int divisor, int size)
{
    long long sum = 0;
    for(int i = 0; i < size; i++)
    {
        sum += ceil((double)nums[i] / divisor);
    }
    return sum;
}

//orgasmic
//time: O(nlog(maxx))
//space: O(1)
int divisor2(vector<int>& nums, int threshold)
{
    int n = nums.size(), min_div = INT_MAX;
    int maxx = INT_MIN;
    if(n > threshold) return -1;
    for(int i = 0; i < n; i++)
    {
        maxx = max(maxx, nums[i]);
    }
    int low = 1, mid, high = maxx;
    while(low <= high)
    {
        mid = (low + high) / 2;
        long long t = calculateSum(nums, mid, n);
        if(t <= threshold)
        {
            min_div = min(min_div, mid);
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return min_div;
}

