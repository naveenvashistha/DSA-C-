#include <bits/stdc++.h>

using namespace std;

void findCombinations(vector<vector<int>> &v, vector<int> &nums, int k, int n, int ind);
vector<vector<int>> combinationSum3(int k, int n);

int main()
{
    vector<vector<int>> out = combinationSum3(3, 10);
    for(auto i: out)
    {
        for(auto j: i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

void findCombinations(vector<vector<int>> &v, vector<int> &nums, int k, int n, int ind)
{
    if(ind == 10 || (n == 0 && k == 0))
    {
        if(n == 0 && k == 0)
            v.push_back(nums);
        return;
    }

    if(n - ind >= 0 && k - 1 >= 0)
    {
        nums.push_back(ind);
        findCombinations(v, nums, k - 1, n - ind, ind + 1);

        nums.pop_back();
    }

    findCombinations(v, nums, k, n, ind + 1);
}

//orgasmic
//time: O(2^n*k)
//space: O(2^n*k)
vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> v;
    vector<int> nums;
    findCombinations(v, nums, k, n, 1);
    return v;
}