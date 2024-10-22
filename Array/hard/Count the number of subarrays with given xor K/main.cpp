#include <bits/stdc++.h>

using namespace std;

int subarraysWithSumK1(vector<int>& a, int b);
int subarraysWithSumK2(vector<int>& a, int b);

int main()
{
    vector<int> arr = {2,2,0,1,2,1};
    cout << subarraysWithSumK1(arr, 2) << endl;
    // cout << subarraysWithSumK2(arr) << endl;
}

//better approach
//time: O(n^2)
//space: O(1)
int subarraysWithSumK1(vector<int> &a, int b)
{
    int n = a.size();
    int xorr, cnt = 0;
    for(int i = 0; i < n; i++)
    {
        xorr = 0;
        for(int j = i; j < n; j++)
        {
            xorr = xorr ^ a[j];
            if(xorr == b)
                cnt++;
        }
    }
    return cnt;
}

//orgasmic 
//time: O(n)
//space: O(n)
int subarraysWithSumK2(vector<int> &a, int b)
{
    int n = a.size();
    unordered_map<int, int> m;
    int xorr = 0, cnt = 0;
    m[0] = 1;
    for(int i = 0; i < n; i++)
    {
        xorr ^= a[i];
        cnt += m[xorr ^ b];
        m[xorr]++;
    }
    return cnt;
}