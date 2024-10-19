#include <bits/stdc++.h>

using namespace std;

int removeDuplicates(vector<int>& nums);

int main()
{
    vector<int> num {1,1,2,2,2,2,3,3,3,3,4,4,4};
    int k = removeDuplicates(num);
    for(int i = 0; i < k; i++)
    {
        cout << num[i] << " ";
    }
    cout << endl;
    cout << k << endl;
}

int removeDuplicates(vector<int>& nums) {
    int i = 1, j = 1;
    int n = nums.size();
    while(i != n)
    {
        if (nums[i] != nums[i - 1])
        {
            nums[j] = nums[i];
            j++;
        }
        i++;
    }
    return j;
}