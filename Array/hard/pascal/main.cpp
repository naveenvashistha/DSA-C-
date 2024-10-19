#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> generate_pascal1(int numRows);
int generate_pascal2(int numRows, int numColumns);
void generate_pascal3(int numRows);
void generate_pascal4(int numRows);

int main()
{
    int n = 1;
    // vector<vector<int>> temp = generate_pascal1(n);
    // int res = generate_pascal2(7,4);
    // cout << res << endl;
    // generate_pascal3(3);
    generate_pascal4(5);
    // for(auto i: temp)
    // {
    //     for(auto j: i)
    //         cout << j << " ";
    //     cout << endl;
    // }
}



//variation 3
//my approach
//time: O(n^2)
//space: O(1) as we are using 2d vector to store the answer and not to calculate it
vector<vector<int>> generate_pascal1(int numRows)
{
    vector<vector<int>> temp = {{1}};
    vector<int> t;
    for(int i = 1; i < numRows; i++)
    {
        t.push_back(1);
        for(int j = 0; j < i - 1; j++)
        {
            t.push_back(temp[i - 1][j] + temp[i - 1][j + 1]);
        }
        t.push_back(1);
        temp.push_back(t);
        t.clear();
    }
    return temp;        
}

//variant 1
//given r and c & asked to find (r,c) element of pascal triangle, just find r-1(C)c-1
//time: O(C - 1)
//space: O(1)
int generate_pascal2(int numRows, int numColumns)
{
    int res = 1;
    for(int i = 0; i < numColumns - 1; i++)
    {
        res = res * (numRows - 1 - i);
        res = res / (i + 1);
    }
    return res;
}

//variant 2 (naive approach)
//same as variation1 but looping through all columns in a row to get each value in a row
//time: O(n*r) where n is the given row number, and r is the column index which can vary from 0 to n-1.
//space: O(1)
void generate_pascal3(int numRows)
{
    int res;
    for(int i = 1; i <= numRows; i++)
    {
        res = 1;
        for(int j = 0; j < i - 1; j++)
        {
            res = res * (numRows - 1 - j);
            res = res / (j + 1);
        }
        cout << res << " ";
    }
    cout << endl;
}

//variant 2 (orgasmic approach)
//time: O(n)
//space: O(1)
void generate_pascal4(int numRows)
{
    int res = 1;
    cout << res << " "; 
    for(int i = 1; i < numRows; i++)
    {
        res = res * (numRows - i);
        res = res / i;
        cout << res << " ";
    }
    cout << endl;
}