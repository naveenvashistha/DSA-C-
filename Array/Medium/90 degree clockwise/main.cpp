#include <bits/stdc++.h>

using namespace std;

void rotate(vector<vector<int>>& matrix);

int main()
{
    vector<vector<int>> num = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    rotate(num);
    for(auto i: num)
    {
        for(auto j: i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

//orgasmic solution
//take transpose and reverse first and last column & second and second last column and so on (or u can reverse each row)
//time: O(n^2)
//space: O(1)
void rotate(vector<vector<int>>& matrix)
{
    for(int i = 0; i < matrix.size(); i++)
    {
        for(int j = 0; j < i; j++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
    for(int i = 0; i < matrix.size() / 2; i++)
    {
        for(int j = 0; j < matrix.size(); j++)
        {
            int temp = matrix[j][i];
            matrix[j][i] = matrix[j][matrix.size() - i - 1];
            matrix[j][matrix.size() - i - 1] = temp;
        }
    }
}


