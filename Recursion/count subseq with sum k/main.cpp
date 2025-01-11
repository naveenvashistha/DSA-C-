#include <bits/stdc++.h>

using namespace std;

int countSub(int ind, vector<int> &nums, int target, vector<int> arr, int sum);
int perfectSum(vector<int>& arr, int target);

int main()
{
    vector<int> arr = {12,2,4,3,4,5};
    int out = perfectSum(arr, 3);
    cout << out << endl;
}

int countSub(int ind, vector<int> &nums, int target, vector<int> arr, int sum)
{
    if(ind == arr.size())
    {
        if(sum == target)
            return 1;
        return 0;
    }
    sum += arr[ind];
    nums.push_back(arr[ind]);
    int l = countSub(ind + 1, nums, target, arr, sum);
    
    sum -= arr[ind];
    nums.pop_back();
    int r = countSub(ind + 1, nums, target, arr, sum);
    
    return l + r;
}

//brute
//time: O(2^n)
//space: O(n)(storage space) & O(n) recurisve stack space
int perfectSum(vector<int>& arr, int target) {
    // code here
    vector<int> nums;
    return countSub(0, nums, target, arr, 0);
}