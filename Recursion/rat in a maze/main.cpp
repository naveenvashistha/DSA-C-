#include <bits/stdc++.h>

using namespace std;

bool findWord(vector<vector<char>>& board, string word, int ind, int row, int column);
bool exist(vector<vector<char>>& board, string word);

int main()
{
    vector<vector<char>> board = {{'A', 'B', 'C'}, {'B', 'C', 'A'}};
    string word = "ABB";
    cout << exist(board, word) << endl;
}
//orgasmic
//time: O(n*n*4^k) where k is the length of word
//space: O(k) recursive space
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
    
    findPath(mat, ans, path + "D", row + 1, col, n);
    findPath(mat, ans, path + "R", row, col + 1, n);
    findPath(mat, ans, path + "U", row - 1, col, n);
    findPath(mat, ans, path + "L", row, col - 1, n);
    
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
    findPath(mat, ans, path, 0, 0, n);
    sort(ans.begin(), ans.end());
    return ans;
}