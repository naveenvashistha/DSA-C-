#include <bits/stdc++.h>

using namespace std;

bool check(vector<int>& nums);

int main()
{
    vector<int> num {3, 4, 5, 1, 2};
    cout << check(num) << endl;
}

//time: O(n^2)
//space: O(n)
bool check(vector<int>& nums) {
    vector<int> B(nums.size());
    for(int x = 0; x <= nums.size(); x++)
    {
        bool found = false;
        for(int i = 0; i < nums.size(); i++)
        {
            B[(i + x) % nums.size()] = nums[i];
        }

        for(int k = 0; k < nums.size(); k++)
            cout << B[k] << " ";
        cout << endl;
        for(int j = 0; j < nums.size() - 1; j++)
        {
            if(B[j] > B[j + 1])
            {
                found = true;
                break;
            }
        }
        if (found == false)
            return true;
    }
    return false;
}


//better solution. Uses the logic that if there is more than one break in inc order of array then it is not able
//to sort even after any rotation
//time O(n)
//space O(1)
bool check(vector<int>& nums) {
    int  count = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        if(nums[i] > nums[(i + 1) % nums.size()])
            count++;
    }
    return count <= 1;
}