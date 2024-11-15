#include <bits/stdc++.h>

using namespace std;

int median1(vector<vector<int>> &matrix, int m, int n);
int median2(vector<vector<int>> &matrix, int m, int n);
int calcUpperBound(vector<int> arr, int target);

int main()
{
    vector<vector<int>> nums = {{1,2,3}, {4,5,6}, {7,8,9}};
    int n = median2(nums, 3, 3);
    cout << n << endl;
}

//brute
//time: O(n*m + n*mlog(n*m))
//space: O(n*m)
int median1(vector<vector<int>> &matrix, int m, int n)
{
    vector<int> list;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
            list.push_back(matrix[i][j]);
    }
    sort(list.begin(), list.end());
    return list[(m * n) / 2];
}

//orgasmic
//time: O(m*logn*log(n*m))
//space: O(1)
int median2(vector<vector<int>> &matrix, int m, int n)
{
    int low, high, mid;
    for (int i = 0; i < m; i++) {
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][n - 1]);
    }
    int noOfElementLeftToMedian = (n * m) / 2;
    while(low <= high)
    {
        mid = (low + high) / 2;
        int cnt = 0;
        for(int i = 0; i < m; i++)
        {
            cnt += calcUpperBound(matrix[i], mid);
        }
        if(cnt <= noOfElementLeftToMedian) low = mid + 1;
        else high = mid - 1;
    }
    return low;
}


int calcUpperBound(vector<int> arr, int target)
{
    int low = 0, high = arr.size() - 1, mid;
    int ans = arr.size();
    while(low <= high)
    {
        mid = (low + high) / 2;
        if(target < arr[mid])
        {
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return ans;
}