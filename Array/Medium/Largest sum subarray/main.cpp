#include <bits/stdc++.h>

using namespace std;

int maxSubArray1(int arr[], int n);
int maxSubArray2(int arr[], int n);
int maxSubArray3(int arr[], int n);

int main()
{
    int arr[] = {1};
    // int n = maxSubArray1(arr, 8);
    // int n = maxSubArray2(arr, 8);
    int n = maxSubArray3(arr, 1);
    cout << n << endl; 
}

//brute force approach
//time: O(n^2) for best and average but O(n^2) for worst
//space: O(1)
int maxSubArray1(int nums[], int n)
{
    int max = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        int sum = 0;
        for(int j = i; j < n; j++)
        {
            sum += nums[j];
            if(sum > max)
                max = sum;
        }
    }
    return max;
}

//kadane's algo
//orgasmic solution
//time: O(n)
//space: O(1)
int maxSubArray2(int nums[], int n)
{
    int sum = 0;
    int maxi = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        sum += nums[i];
        maxi = max(maxi, sum);
        if(sum < 0)
            sum = 0;
    }
    return maxi;
}

//extension to kadane's algo where we also print the respective subarray
int maxSubArray3(int nums[], int n)
{
    int sum = 0;
    int maxi = INT_MIN;
    int temp = 0;
    int min_index;
    int max_index;
    for(int i = 0; i < n; i++)
    {
        sum += nums[i];
        if(maxi < sum)
        {
            maxi = sum;
            max_index = i;
            min_index = temp;
        }
        if(sum < 0)
        {
            sum = 0;
            temp = i + 1;
        }
    }
    for(int i = min_index; i <= max_index; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    return maxi;
}