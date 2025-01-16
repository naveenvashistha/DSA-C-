#include <bits/stdc++.h>

using namespace std;

vector<string> findPath(vector<vector<int>> &mat) ;
void findPaths(vector<vector<int>> &mat, vector<string> &ans, string path, int row, int col, int n);

int main()
{
    vector<vector<int>> mat = {{1, 0, 1}, {1, 0, 1}, {1, 1, 1}};
    string path = "";
    vector<string> out = findPath(mat);
    for(auto i: out)
    {
        for(auto j: i)
            cout << j << " ";
        cout << endl;
    }
}

void findPath(vector<vector<int>> &mat, vector<string> &ans, string path, int row, int col, int n)
{
    if(row == n - 1 && col == n - 1)
    {
        ans.push_back(path);
        return;
    }
    if(row < 0 || col < 0 || row == n || col == n || mat[row][col] == 0)
        return;
    int pos = mat[row][col];
    mat[row][col] = 0;
    
    findPaths(mat, ans, path + "D", row + 1, col, n);
    findPaths(mat, ans, path + "R", row, col + 1, n);
    findPaths(mat, ans, path + "U", row - 1, col, n);
    findPaths(mat, ans, path + "L", row, col - 1, n);
    
    mat[row][col] = pos;
}

//orgasmic
//time: O(4^(n*n))
//space: O(n*n) recursive, O(k) storage space
vector<string> findPath(vector<vector<int>> &mat) {
    // code here
    int n = mat.size();
    vector<string> ans;
    string path = "";
    if(mat[0][0] == 0 || mat[n - 1][n - 1] == 0) return ans;
    findPaths(mat, ans, path, 0, 0, n);
    sort(ans.begin(), ans.end());
    return ans;
}