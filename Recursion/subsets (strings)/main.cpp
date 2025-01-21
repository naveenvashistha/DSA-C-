#include <bits/stdc++.h>

using namespace std;

void sub(set<vector<int>> &v, vector<int> nums);
vector<vector<int>> subsets(vector<int>& nums);
vector<vector<int>> subsets1(vector<int>& nums);
vector<vector<int>> subsets2(vector<int>& nums); 
void chooseOrnot(vector<vector<int>> &v, vector<int> &num, int ind, vector<int> nums, int n);

int main()
{
    vector<int> v = {1,2,4};
    vector<vector<int>> s = subsets(v);
    for(auto i: s)
    {
        for(auto j: i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

void sub(set<vector<int>> &v, vector<int> nums)
{      
    v.insert(nums);  
    int len = nums.size();
    for(int i = 0; i < len; i++)
    {
        int n = nums[i];
        nums.erase(nums.begin() + i);
        sub(v, nums);
        nums.insert(nums.begin() + i, n);
    }
    return;
}

//brute (recursion)
//time: O(n^2*n!)
//space: O(n) as recursive depth is not greater than size of nums
vector<vector<int>> subsets(vector<int>& nums) {
    set<vector<int>> v;
    sub(v, nums);
    vector<vector<int>> vt(v.begin(), v.end());
    return vt;
}

void chooseOrnot(vector<vector<int>> &v, vector<int> &num, int ind, vector<int> nums, int n)
{
    if(ind == n)
    {
        v.push_back(num);
        return;
    }
    num.push_back(nums[ind]);
    chooseOrnot(v, num, ind + 1, nums, n);
    num.pop_back();

    chooseOrnot(v, num, ind + 1, nums, n);
}

//orgasmic
//time: O(n*2^n)
//space: O(2^n*n) for result storage and O(n) for recursive space
vector<vector<int>> subsets1(vector<int>& nums) {
    vector<vector<int>> v;
    vector<int> d;
    chooseOrnot(v, d, 0, nums, nums.size());
    return v;   
}

//orgasmic(bit manipulation)
//time: O(2^n*n)
//space: O(2^n*n)
vector<vector<int>> subsets2(vector<int>& nums) {
    vector<vector<int>> v;
    for(int i = 0; i < pow(2, nums.size()); i++)
    {
        vector<int> num;
        for(int j = 0; j < nums.size(); j++)
        {
            if((i & (1 << j)) != 0)
            {
                num.push_back(nums[j]);
            }
        }
        v.push_back(num);
    }

    return v;   
}