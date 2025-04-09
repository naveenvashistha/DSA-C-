#include <bits/stdc++.h>

using namespace std;

//my solution
//time: O(mxn)
//space: O(mxn)
bool check(int i, int j, vector<vector<char>>& board, vector<vector<int>>& vis, vector<vector<int>>& visited)
{
    queue<pair<int, int>> q;
    int rows = board.size();
    int cols = board[0].size();
    vis[i][j] = 1;
    q.push({i, j});
    while(!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        int r = p.first;
        int c = p.second;
        if(r - 1 >= 0 && board[r - 1][c] == 'O' && !vis[r - 1][c])
        {
            if(visited[r - 1][c] || r - 1 == 0) return false;
            q.push({r - 1, c});
            vis[r - 1][c] = 1;
        }
        if(c - 1 >= 0 && board[r][c - 1] == 'O' && !vis[r][c - 1])
        {
            if(visited[r][c - 1] || c - 1 == 0) return false;
            q.push({r, c - 1});
            vis[r][c - 1] = 1;
        }
        if(r + 1 < rows && board[r + 1][c] == 'O' && !vis[r + 1][c])
        {
            if(visited[r + 1][c] || r + 1 == rows - 1) return false;
            q.push({r + 1, c});
            vis[r + 1][c] = 1;
        }
        if(c + 1 < cols && board[r][c + 1] == 'O' && !vis[r][c + 1])
        {
            if(visited[r][c + 1] || c + 1 == cols - 1) return false;
            q.push({r, c + 1});
            vis[r][c + 1] = 1;
        }
    }
    return true;
}
void solve(vector<vector<char>>& board) {
    int rows = board.size();
    int cols = board[0].size();
    vector<vector<int>> visited(rows, vector<int>(cols, 0));
    for(int i = 1; i < rows - 1; i++)
    {
        for(int j = 1; j < cols - 1; j++)
        {
            if(board[i][j] == 'O')
            {
                vector<vector<int>> vis(rows, vector<int>(cols, 0));
                bool res = check(i, j, board, vis, visited);
                visited[i][j] = 1;
                if(res) board[i][j] = 'X';
            }
        }
    }
}


//orgasmic
//time: O(mxn)
//space: O(mxn)
void bfs(int i, int j, vector<vector<char>>& board, vector<vector<int>>& visited)
{
    queue<pair<int, int>> q;
    int rows = board.size();
    int cols = board[0].size();
    visited[i][j] = 1;
    q.push({i, j});
    while(!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        int r = p.first;
        int c = p.second;
        if(r - 1 >= 0 && board[r - 1][c] == 'O' && !visited[r - 1][c])
        {
            q.push({r - 1, c});
            visited[r - 1][c] = 1;
        }
        if(c - 1 >= 0 && board[r][c - 1] == 'O' && !visited[r][c - 1])
        {
            q.push({r, c - 1});
            visited[r][c - 1] = 1;
        }
        if(r + 1 < rows && board[r + 1][c] == 'O' && !visited[r + 1][c])
        {
            q.push({r + 1, c});
            visited[r + 1][c] = 1;
        }
        if(c + 1 < cols && board[r][c + 1] == 'O' && !visited[r][c + 1])
        {
            q.push({r, c + 1});
            visited[r][c + 1] = 1;
        }
    }
}
void solve(vector<vector<char>>& board) {
    int rows = board.size();
    int cols = board[0].size();
    vector<vector<int>> visited(rows, vector<int>(cols, 0));
    for(int i = 0; i < cols; i++)
    {
        if(board[0][i] == 'O' && !visited[0][i]) bfs(0, i, board, visited);
    }
    for(int i = 0; i < cols; i++)
    {
        if(board[rows - 1][i] == 'O' && !visited[rows - 1][i]) bfs(rows - 1, i, board, visited);
    }
    for(int i = 1; i < rows - 1; i++)
    {
        if(board[i][0] == 'O' && !visited[i][0]) bfs(i, 0, board, visited);
    }
    for(int i = 1; i < rows - 1; i++)
    {
        if(board[i][cols - 1] == 'O' && !visited[i][cols - 1]) bfs(i, cols - 1, board, visited);
    }
    for(int i = 1; i < rows - 1; i++)
    {
        for(int j = 1; j < cols - 1; j++)
        {
            if(board[i][j] == 'O' && !visited[i][j]) board[i][j] = 'X';
        }
    }
}