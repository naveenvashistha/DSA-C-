#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> subsetsWithDup(vector<int>& arr);
void findCombinations(vector<vector<int>> &v, vector<int> &arr, vector<int> &nums, int ind);

int main()
{
    vector<int> arr = {2,3,6,7};
    vector<vector<int>> out = subsetsWithDup(arr);
    for(auto i: out)
    {
        for(auto j: i)
            cout << j << " ";
        cout << endl;
    }
}

void findCombinations(vector<vector<int>> &v, vector<int> &arr, vector<int> &nums, int ind)
{
    if(ind == arr.size())
    {
        return;
    }
    for(int i = ind; i < arr.size(); i++)
    {
        if(i == ind || arr[i] != arr[i - 1])
        {
            nums.push_back(arr[i]);
            v.push_back(nums);
            findCombinations(v, arr, nums, i + 1);

            nums.pop_back();
        }
    }
}

//orgasmic
//time: O(k*2^n)
//space: O(k*2^n)
vector<vector<int>> subsetsWithDup(vector<int>& arr) {
    vector<vector<int>> v;
    vector<int> nums;
    v.push_back(nums);
    sort(arr.begin(), arr.end());
    findCombinations(v, arr, nums, 0);
    return v;
}