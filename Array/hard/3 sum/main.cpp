#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> threeSum1(vector<int>& nums);
vector<vector<int>> threeSum2(vector<int>& nums);
vector<vector<int>> threeSum3(vector<int>& nums);

int main()
{
    vector<int> v = {2,2,0,1,2,1};
    vector<vector<int>> temp = threeSum1(v);
    for(auto i: temp)
    {
        for(auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

//brute force
//time: O(N^3 * log(no. of unique triplets)), where N = size of the array.
//space: O(N)
vector<vector<int>> threeSum1(vector<int>& nums)
{
    int n = nums.size();
    set<vector<int>> s;
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            for(int k = j + 1; k < n; k++)
            {
                if(nums[i] + nums[j] + nums[k] == 0)
                {
                    vector<int> t = {nums[i], nums[j], nums[k]};
                    sort(t.begin(), t.end());
                    s.insert(t);
                }
            }
        }
    }
    vector<vector<int>> temp(s.begin(), s.end());
    return temp;
}

//better approach
//time: O(N^2 * log(no. of unique triplets))
//space: O(no. of the unique triplets) + O(N (for hashset))
vector<vector<int>> threeSum1(vector<int>& nums)
{
    int n = nums.size();
    set<vector<int>> s;
    for(int i = 0; i < n; i++)
    {
        set<int> hashset;
        for(int j = i + 1; j < n; j++)
        {
            int third = -(nums[i] + nums[j]);
            if(hashset.find(third) != hashset.end())
            {
                vector<int> t = {nums[i], nums[j], third};
                sort(t.begin(), t.end());
                s.insert(t);
            }
            hashset.insert(nums[j]);
        }
    }
    vector<vector<int>> temp(s.begin(), s.end());
    return temp;
}

//orgasmic
//time: O(N^2 * log(no. of unique triplets))
//space: O(no. of the unique triplets) + O(N (for hashset))
vector<vector<int>> threeSum1(vector<int>& nums)
{
    int n = nums.size();
    int j,k, sum;
    vector<vector<int>> temp;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < n; i++)
    {
        if(i != 0 && nums[i] == nums[i - 1]) continue;
        j = i + 1;
        k = n - 1;
        while(j < k)
        {
            sum = nums[i] + nums[j] + nums[k];
            if(sum > 0)
                k--;
            else if(sum < 0)
                j++;
            else
            {
                temp.push_back({nums[i], nums[j], nums[k]});
                j++;
                k--;
                while(j < k && nums[j] == nums[j - 1]) j++;
                while(j < k && nums[k] == nums[k + 1]) k--;
            }
            
        }
    }
    return temp;
}