#include <bits/stdc++.h>

using namespace std;

int linearSearch(vector<int>& nums, int k);

int main()
{
    vector<int> num {1,2,3,4,5};
    cout << linearSearch(num, 0) << endl;
}

//time: O(n)
//space: O(1)
int linearSearch(vector<int>& num, int k)
{
    for(int i = 0; i < num.size(); i++)
    {
        if(num[i] == k) return i;
    }
    return -1;
}