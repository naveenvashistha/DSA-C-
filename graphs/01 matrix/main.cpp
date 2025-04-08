#include <bits/stdc++.h>

using namespace std;

//orgasmic
//time: O(mxn)
//space: O(mxn)
vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    queue<pair<pair<int, int>, int>> q;
    int rows = mat.size(), cols = mat[0].size();
    vector<vector<int>> ans(rows, vector<int>(cols, 0));
    vector<vector<int>> visited(rows, vector<int>(cols, 0));
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            if(mat[i][j] == 0)
            {
                visited[i][j] = 1;
                q.push({{i, j}, 0});
            }
        }
    }
    while(!q.empty())
    {
        pair<pair<int, int>, int> p = q.front();
        int r = p.first.first;
        int c = p.first.second;
        q.pop();
        ans[r][c] = p.second;
        if(r - 1 >= 0 && !visited[r - 1][c]){
            q.push({{r - 1, c}, p.second + 1});
            visited[r - 1][c] = 1;
        }
        if(r + 1 < rows && !visited[r + 1][c]){
            q.push({{r + 1, c}, p.second + 1});
            visited[r + 1][c] = 1;
        }
        if(c - 1 >= 0 && !visited[r][c - 1]){
            q.push({{r, c - 1}, p.second + 1});
            visited[r][c - 1] = 1;
        }
        if(c + 1 < cols && !visited[r][c + 1]){
            q.push({{r, c + 1}, p.second + 1});
            visited[r][c + 1] = 1;
        }
    }
    return ans;
}