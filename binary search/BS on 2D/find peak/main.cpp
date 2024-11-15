#include <bits/stdc++.h>

using namespace std;

vector<int> findPeakGrid(vector<vector<int>>& mat);

int main()
{
    vector<vector<int>> nums = {{1,2,3}, {4,5,6}, {7,8,9}};
    vector<int> n = findPeakGrid(nums);
    for(auto i: n) cout << i << endl;
}

//orgasmic
//time: O(nlogm)
//space: O(1)
vector<int> findPeakGrid(vector<vector<int>>& mat) {
    int rows = mat.size(), cols = mat[0].size();
    int low = 0, high = cols - 1, mid;
    while(low <= high)
    {
        mid = (low + high) / 2;
        int max_row_index = 0;
        for(int i = 0; i < rows; i++)
        {
            if(mat[max_row_index][mid] < mat[i][mid]) max_row_index = i;
        }
        int left = -1, right = -1;
        if(mid != 0) left = mat[max_row_index][mid - 1];
        if(mid != cols - 1) right = mat[max_row_index][mid + 1];
        if(mat[max_row_index][mid] > left && mat[max_row_index][mid] > right) return {max_row_index, mid};
        else if(mat[max_row_index][mid] < left) high = mid - 1;
        else low = mid + 1;
    }
    return {-1, -1};
}