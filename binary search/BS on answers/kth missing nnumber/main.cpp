#include <bits/stdc++.h>

using namespace std;

int findKthPositive1(vector<int>& arr, int k);
int findKthPositive2(vector<int>& arr, int k);
int findKthPositive3(vector<int>& arr, int k);

int main()
{
    vector<int> nums = {2,3,4,7,11};
    int n = findKthPositive1(nums, 5);
    cout << n << endl;
}

//brutal (my approach)
//time: O(n)
//space: O(1)
int findKthPositive1(vector<int>& arr, int k)
{
    int n = arr.size();
    int i = 0, missing = 1, missing_count = 0;
    while(missing_count != k)
    {
        if(i >= n || missing < arr[i])
        {
            missing_count++;
            if(missing_count == k) return missing;
        }
        else if(i < n) i++;
        missing++;
    }
}

//if k = 5 then 5th missing number would be 5 if all the numbers till 5 are missing from array
//but if thats not the case then we will shift the actual answer which is 5 by 1
//brutal(striver)
//time: O(n)
//space: O(1)
int findKthPositive2(vector<int>& arr, int k)
{
    int n = arr.size();
    for(int i = 0; i < n; i++)
    {
        if(arr[i] <= k) k++;
        else break;
    }
    return k;
}

//find two nearby indexes b/w which our kth missing number exist
//for that we will use the property that for any index i, i+1 should have been there if numbers were not missing, so till ith index, arr[i] - (i+1) numbers would be missing
//high would be starting index of nearby indexes after loop ends
//then kth missing number would be arr[high] + (k - numbers missing till high)
//time: O(logn)
//space: O(1)
int findKthPositive3(vector<int>& arr, int k)
{
    int n = arr.size();
    int low = 0, high = n - 1, mid;
    if(k < arr[low]) return k;
    while(low <= high)
    {
        mid = (low + high) / 2;
        int missing_numbers_till_mid = arr[mid] - (mid + 1);
        if(missing_numbers_till_mid <= k)
            high = mid - 1;
        else
            low = mid + 1;
    } 
    return arr[high] + (k - (arr[high] - (high + 1)));
}