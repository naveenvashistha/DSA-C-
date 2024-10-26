#include <bits/stdc++.h>

using namespace std;

int maxProduct1(vector<int>& nums);
int maxProduct2(vector<int>& nums);

int main()
{
    vector<int> v = {3,2,1,4};
    int temp = maxProduct1(v);
    cout << temp << endl;
}

int maxProduct1(vector<int>& nums)
{
    int n = nums.size();
    int prod= 1;
    int max_prod = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        prod = 1;
        for(int j = i; j < n; j++)
        {
            prod *= nums[j];
            max_prod = max(max_prod, prod);
        }
    }
    return max_prod;
}

//orgasmic solution
//time: O(n)
//space: O(1)
int maxProduct2(vector<int>& nums)
{
    int n = nums.size();
    int pref = 1, suff = 1;
    int max_prod = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        if(pref == 0) pref = 1;
        if(suff == 0) suff = 1;
        pref *= nums[i];
        suff *= nums[n - 1 - i];
        max_prod = max(pref, max(max_prod, suff)); 
    }
    return max_prod;
}