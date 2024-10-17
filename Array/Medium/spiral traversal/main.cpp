#include <bits/stdc++.h>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix);

int main()
{
    vector<vector<int>> num = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    vector<int> temp = spiralOrder(num);
    for(auto i: temp)
        cout << i << " ";
    cout << endl;
}

//orgasmic solution
//time: O(n^2)
//space: O(n)
vector<int> spiralOrder(vector<vector<int>>& matrix)
{
    int top = 0, bottom = matrix.size() - 1, left = 0, right = matrix[0].size() - 1;
    vector<int> temp;
    while(top <= bottom && left <= right)
    {
        //traversing left to right
        for(int i = left; i <= right; i++)
        {
            temp.push_back(matrix[top][i]);
        }
        top++;
        //traversing top to bottom
        for(int i = top; i <= bottom; i++)
        {
            temp.push_back(matrix[i][right]);
        }
        right--;
        //traversing right to left
        for(int i = right; i >= left; i--)
        {
            if(top <= bottom)
                temp.push_back(matrix[bottom][i]);
        }
        bottom--;
        //traversing bottom to top
        for(int i = bottom; i >= top; i--)
        {
            if(left <= right)
                temp.push_back(matrix[i][left]);
        }
        left++;
    }
    return temp;
}


