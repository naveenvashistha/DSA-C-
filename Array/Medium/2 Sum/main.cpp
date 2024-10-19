#include <bits/stdc++.h>

using namespace std;

vector<int> twoSum1(int arr[], int n, int target);
vector<int> twoSum2(int arr[], int n, int target);
vector<int> twoSum3(int arr[], int n, int target);

int main()
{
    int arr[] = {1,2,3,4,5};
    // vector<int> n = twoSum1(arr, 5, 7);
    // vector<int> n = twoSum2(arr, 5, 7);
    vector<int> n = twoSum3(arr, 5, 7);
    cout << n[0] << " " << n[1] << endl; 
}

//brute force
//time: O(n^2)
//space: O(1)
vector<int> twoSum1(int arr[], int n, int target)
{
    for(int i = 0; i < n; i++)
    {
        int n = target - arr[i];
        for(int j = 0; j < n; j++)
        {
            if(arr[j] == n && i != j)
                return {i,j};
        }
    }
    return {-1, -1};
}


//optimized approach using hashing
//time: O(n) for best and avg but O(n^2) for worst
//space: O(n)
vector<int> twoSum2(int arr[], int n, int target)
{
    unordered_map<int, int> temp;
    for(int i = 0; i < n; i++)
    {
        if(temp.find(target - arr[i]) != temp.end())
            return {i, temp[target - arr[i]]};
        temp[arr[i]] = i;
    }
    return {-1, -1};
}

//better approach
//time: O(nlogn) + O(n)
//space: O(1)
vector<int> twoSum3(int arr[], int n, int target)
{
    int left = 0, right = n - 1;
    sort(arr, arr + n);
    while(left < right)
    {
        if(arr[left] + arr[right] < target)
            left++;
        else if(arr[left] + arr[right] > target)
            right--;
        else
            return {left, right};
    }
    return {-1, -1};
}