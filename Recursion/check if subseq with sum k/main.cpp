#include <bits/stdc++.h>

using namespace std;

bool isSubsetPresent(int n, int k, vector<int> &a);
bool isSub(int n, int k, vector<int> a, vector<int> &nums, int sum, int ind);

int main()
{
    vector<int> arr = {12,2,4,3,4,5};
    bool out = isSubsetPresent(6, 3, arr);
    cout << out << endl;
}

bool isSub(int n, int k, vector<int> a, vector<int> &nums, int sum, int ind)
{
    if(n == ind)
    {
        if(sum == k) return true;
        return false;
    }
    sum += a[ind];
    nums.push_back(a[ind]);
    if(isSub(n, k, a, nums, sum, ind + 1)) return true;
    sum -= a[ind];
    nums.pop_back();
    if(isSub(n, k, a, nums, sum, ind + 1)) return true;
    return false;
}

//brute
//time: O(2^n)
//space: O(n) for recursive space, O(n) for storage space
bool isSubsetPresent(int n, int k, vector<int> &a)
{
    // Write your code here
    vector<int> nums;
    return isSub(n, k, a, nums, 0, 0);
}