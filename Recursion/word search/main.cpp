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
//time: O(m*n*4^k) where k is the length of word
//space: O(k) recursive space
bool findWord(vector<vector<char>>& board, string word, int ind, int row, int column)
{
    if(ind == word.size()) return true;

    if(row < 0 || column < 0 || row == board.size() || column == board[0].size() || 
    board[row][column] != word[ind] || board[row][column] == '*')
        return false;
    bool a = false;
    bool b = a;
    bool c = a;
    bool d = a;
    char ch = board[row][column];
    board[row][column] = '*';

    a = findWord(board, word, ind + 1, row - 1, column);

    b = findWord(board, word, ind + 1, row + 1, column);

    c = findWord(board, word, ind + 1, row, column - 1);

    d = findWord(board, word, ind + 1, row, column + 1);
    board[row][column] = ch;
    return a || b || c || d;
}
bool exist(vector<vector<char>>& board, string word) {
    bool res = false;
    for(int i = 0; i < board.size(); i++)
    {
        for(int j = 0; j < board[0].size(); j++)
        {
            if(board[i][j] == word[0])
                res = findWord(board, word, 0, i, j);
            if(res) return res;
        }
    }
    return res;
}