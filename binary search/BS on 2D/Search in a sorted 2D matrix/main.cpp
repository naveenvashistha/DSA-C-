#include <bits/stdc++.h>

using namespace std;

bool searchMatrix1(vector<vector<int>>& matrix, int target);
bool searchMatrix2(vector<vector<int>>& matrix, int target);

int main()
{
    vector<vector<int>> nums = {{1,2,3}, {4,5,6}, {7,8,9}};
    bool n = searchMatrix2(nums, 3);
    cout << n << endl;
}

//better
//time: O(nlogm)
//space: O(1)
bool searchMatrix1(vector<vector<int>>& matrix, int target)
{
    int rows = matrix.size(), cols = matrix[0].size();
    for(int i = 0; i < rows; i++)
    {
        if(matrix[i][0] <= target && matrix[i][cols - 1] >= target)
        {
            int low = 0, high = cols - 1, mid;
            while(low <= high)
            {
                mid = (low + high) / 2; 
                if(matrix[i][mid] == target) return true;
                else if(matrix[i][mid] <= target) low = mid + 1;
                else high = mid - 1;
            }
        }
    }
    return false;
}

//orgasmic
//time: O(logm*n)
//space: O(1)
bool searchMatrix2(vector<vector<int>>& matrix, int target)
{
    int rows = matrix.size(), cols = matrix[0].size();
    int low = 0, high = rows * cols - 1, mid;
    int r, c;
    while(low <= high)
    {
        mid = (low + high) / 2;
        r = mid / cols;
        c = mid % cols;
        if(matrix[r][c] == target) return true;
        else if(matrix[r][c] < target) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}
