#include <bits/stdc++.h>

using namespace std;

void setZeroes1(vector<vector<int>>& matrix);
void setZeroes2(vector<vector<int>>& matrix);
void setZeroes3(vector<vector<int>>& matrix);

int main()
{
    vector<vector<int>> num = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    // setZeroes1(num);
    // setZeroes2(num);
    setZeroes3(num);
    for(auto i: num)
    {
        for(auto j: i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

//my approach and also better
//time: O(2*n*m)
//space: O(n + m)
void setZeroes1(vector<vector<int>>& matrix)
{
    unordered_set<int> rows, cols;
    for(int i = 0; i < matrix.size(); i++)
    {
        for(int j = 0; j < matrix[i].size(); j++)
        {
            if(matrix[i][j] == 0)
            {
                rows.insert(i);
                cols.insert(j);
            }
        }
    }
    for(int i = 0; i < matrix.size(); i++)
    {
        for(int j = 0; j < matrix[i].size(); j++)
        {
            if(rows.find(i) != rows.end() || cols.find(j) != cols.end())
            {
                matrix[i][j] = 0;
            }
        }
    }
}

//better and striver's soln
//time: O(n^2)
//space: O(n)
void setZeroes2(vector<vector<int>>& matrix)
{
    int rows[matrix.size()] = {0}, cols[matrix[0].size()] = {0};
    for(int i = 0; i < matrix.size(); i++)
    {
        for(int j = 0; j < matrix[i].size(); j++)
        {
            if(matrix[i][j] == 0)
            {
                rows[i] = 1;
                cols[j] = 1;
            }
        }
    }
    for(int i = 0; i < matrix.size(); i++)
    {
        for(int j = 0; j < matrix[i].size(); j++)
        {
            if(rows[i] || cols[j])
            {
                matrix[i][j] = 0;
            }
        }
    }
}

//orgasmic approach
//here we are taking the rows and cols array in previous approach inside the array itself.
//first column to store row details and first row to store column details
//traverse the array with caution
//time: O(n^2)
//space: O(1)
void setZeroes3(vector<vector<int>>& matrix)
{
    int col0 = 1;
    for (int i = 0; i < matrix.size(); i++)
    {
        for(int j = 0; j < matrix[i].size(); j++)
        {
            if(matrix[i][j] == 0)
            {
                if(j == 0)
                {
                    col0 = 0;
                }
                else
                {
                    matrix[0][j] = 0;
                }
                matrix[i][0] = 0; 
            }
        }
    }
    for(int i = 1; i < matrix.size(); i++)
    {
        for(int j = 1; j < matrix[i].size(); j++)
        {
            if(matrix[0][j] == 0 || matrix[i][0] == 0)
                matrix[i][j] = 0;
        }
    }
    if(matrix[0][0] == 0)
    {
        for(int i = matrix[0].size() - 1; i >= 1; i--)
            matrix[0][i] = 0;
    }
    if(col0 == 0)
    {
        for(int i = 0; i < matrix.size(); i++)
            matrix[i][0] = 0;
    }
}