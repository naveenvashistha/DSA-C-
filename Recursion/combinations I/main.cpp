#include <bits/stdc++.h>

using namespace std;

void findSub(vector<vector<int>> &v, vector<int> &nums, vector<int> candidates, int ind, int target);
vector<vector<int>> combinationSum(vector<int>& candidates, int target);

int main()
{
    vector<int> arr = {12,2,4,3,4,5};
    vector<vector<int>> out = combinationSum(arr, 3);
    for(auto i: out)
    {
        for(auto j: i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

void findSub(vector<vector<int>> &v, vector<int> &nums, vector<int> candidates, int ind, int target)
{
    if(ind == candidates.size())
    {
        if(target == 0)
        {
            v.push_back(nums);
        }
        return;
    }
    if(target - candidates[ind] >= 0)
    {
        nums.push_back(candidates[ind]);
        findSub(v, nums, candidates, ind, target - candidates[ind]);
        nums.pop_back();
    }

    findSub(v, nums, candidates, ind + 1, target);

}

//brute
//time: O(2^t * k) where k is average length of nums and t is target
//space: O(k*x) where k is average length of nums and x is no of possible combinations
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> v;
    vector<int> nums;
    findSub(v, nums, candidates, 0, target);
    return v;
}