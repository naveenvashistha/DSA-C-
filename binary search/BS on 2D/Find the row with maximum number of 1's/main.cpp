#include <bits/stdc++.h>

using namespace std;

int rowWithMax1s_1(vector<vector<int>> &matrix, int n, int m);
int rowWithMax1s_2(vector<vector<int>> &matrix, int n, int m);

int main()
{
    vector<vector<int>> nums = {{1,1,1}, {0,0,1}, {1,1,0}};
    int n = rowWithMax1s_1(nums, 3, 3);
    cout << n << endl;
}

//brute
//time: O(n^2)
//sapce: O(1)
int rowWithMax1s_1(vector<vector<int>> &matrix, int n, int m)
{
    int max_row_index = -1;
    int max_ones = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(matrix[i][j] == 1 && m - j > max_ones)
            {
                max_row_index = i;
                max_ones = m - j;
                break;
            }
        }
    }
    return max_row_index;
}

//orgasmic
//time: O(nlogm)
//space: O(1)
int rowWithMax1s_2(vector<vector<int>> &matrix, int n, int m)
{
    int max_row_index = -1;
    int ans = INT_MAX;
    int max_ones = INT_MAX;
    for(int i = 0; i < n; i++)
    {
        int low = 0, high = m - 1, mid;
        while(low <= high)
        {
            mid = (high + low) / 2;
            if(matrix[i][mid] >= 1)
            {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        if(ans < max_ones)
        {
            max_ones = ans;
            max_row_index = i;
        }
    }
    return max_row_index;
}
