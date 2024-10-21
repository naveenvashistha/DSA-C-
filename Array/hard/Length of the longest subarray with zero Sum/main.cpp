#include <bits/stdc++.h>

using namespace std;

int getLongestZeroSumSubarrayLength1(vector<int> &arr);
int getLongestZeroSumSubarrayLength2(vector<int> &arr);

int main()
{
    vector<int> arr = {2,2,0,1,2,1};
    cout << getLongestZeroSumSubarrayLength1(arr) << endl;
    // cout << getLongestZeroSumSubarrayLength2(arr) << endl;
}

//brute force
//time: O(n^2)
//space: O(1)
int getLongestZeroSumSubarrayLength1(vector<int> &arr)
{
    int n = arr.size();
    int max_count = 0, sum = 0, cnt = 0;
    for(int i = 0; i < n; i++)
    {
        cnt = sum = 0;
        for(int j = i; j < n; j++)
        {
            sum += arr[j];
            cnt++;
            if(sum == 0 && cnt > max_count)
                max_count = cnt;
        }
    }
    return max_count;
}

//orgasmic (just remember that if sum already exist in the map then dont update its indices)
//time: O(n)
//space: O(n)
int getLongestZeroSumSubarrayLength2(vector<int> &arr)
{
    int n = arr.size(), sum = 0, max_count = 0;
    unordered_map<int, int> m;
    for(int i = 0; i < n; i++)
    {
        sum += arr[i];
        if(sum == 0)
        {
            max_count = max(max_count, i + 1);
        }
        else if(m.find(sum) != m.end())
        {
            max_count = max(max_count, i - m[sum]);
        }    
        else
        {
            m[sum] = i;
        }
    }
    return max_count;
}