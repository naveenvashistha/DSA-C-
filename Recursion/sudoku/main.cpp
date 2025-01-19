#include <bits/stdc++.h>

using namespace std;

void solveSudoku(vector<vector<char>>& board);
bool isSafe(vector<vector<char>>& board, char i, int row, int col);
bool fillPos(vector<vector<char>>& board, int row, int col);

int main()
{
    vector<vector<char>>board{
        {'9', '5', '7', '.', '1', '3', '.', '8', '4'},
        {'4', '8', '3', '.', '5', '7', '1', '.', '6'},
        {'.', '1', '2', '.', '4', '9', '5', '3', '7'},
        {'1', '7', '.', '3', '.', '4', '9', '.', '2'},
        {'5', '.', '4', '9', '7', '.', '3', '6', '.'},
        {'3', '.', '9', '5', '.', '8', '7', '.', '1'},
        {'8', '4', '5', '7', '9', '.', '6', '1', '3'},
        {'.', '9', '1', '.', '3', '6', '.', '7', '5'},
        {'7', '.', '6', '1', '8', '5', '4', '.', '9'}
    };
    solveSudoku(board);
    for(int i= 0; i< 9; i++){
        for(int j= 0; j< 9; j++)
            cout<<board[i][j]<<" ";
            cout<<"\n";
    }
}

bool isSafe(vector<vector<char>>& board, char i, int row, int col)
{
    for(int k = 0; k < 9; k++)
    {
        if(board[row][k] == i) return false;
        if(board[k][col] == i) return false;
    }
    row = row - row % 3;
    col = col - col % 3;
    for(int k = row; k < row + 3; k++)
    {
        for(int l = col; l < col + 3; l++)
        {
            if(board[k][l] == i) return false;
        }
    }
    return true;
}
bool fillPos(vector<vector<char>>& board, int row, int col)
{
    if(row == 9) return true;
    if(board[row][col] == '.')
    {
        for(char i = '1'; i <= '9'; i++)
        {
            if(isSafe(board, i, row, col))
            {
                board[row][col] = i;
                bool res = fillPos(board, col == 8 ? row + 1 : row, col == 8 ? 0 : col + 1);
                if(res == true) return true;
                board[row][col] = '.';
            }
        }
        return false;
    }
    else
    {
        bool res = fillPos(board, col == 8 ? row + 1 : row, col == 8 ? 0 : col + 1);
        return res;
    }
}

//orgasmic
//time: O(9^81 * 27)
//space: O(1)
void solveSudoku(vector<vector<char>>& board) {
    bool res = fillPos(board, 0, 0);
}