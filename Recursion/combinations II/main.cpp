#include <bits/stdc++.h>

using namespace std;

void findSub(vector<vector<int>> &v, vector<int> &nums, vector<int> candidates, int ind, int target);
vector<vector<int>> combinationSum2(vector<int>& candidates, int target);

int main()
{
    vector<int> arr = {1,1,2,5,6,7,10};
    vector<vector<int>> out = combinationSum2(arr, 8);
    for(auto i: out)
    {
        for(auto j: i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

void findSum(vector<vector<int>> &v, vector<int> &nums, vector<int> &candidates, int ind, int target)
{
    if(ind == candidates.size() || target == 0)
    {
        if(target == 0)
            v.push_back(nums);
        return;
    }
    for(int i = ind; i < candidates.size(); i++)
    {
        if(target - candidates[i] >= 0)
        {
            if(i == ind || candidates[i - 1] != candidates[i])
            {
                nums.push_back(candidates[i]);
                findSum(v, nums, candidates, i + 1, target - candidates[i]);
                nums.pop_back();
                
                if(target - candidates[i] == 0) return;
            }
        }
        else return;
    }
}

//orgasmic
//time: O(2^n*k)
//space: O(k*x)
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> v;
    vector<int> nums;
    sort(candidates.begin(), candidates.end());
    findSum(v, nums, candidates, 0, target);
    return v;
}