#include <bits/stdc++.h>

using namespace std;

vector<vector<string>> solveNQueens(int n) ;
void findPos(vector<vector<string>> &ans, vector<string> &v, string &s, int ind, int n, vector<pair<int, int>> &pos);

int main()
{
    vector<vector<string>> ans = solveNQueens(4);
    for(auto i: ans)
    {
        for(auto j: i)
            cout << j << endl;
        cout << endl;
    }
}

void findPos(vector<vector<string>> &ans, vector<string> &v, string &s, int ind, int n, vector<pair<int, int>> &pos)
{
    if(ind == n)
    {
        if(v.size() == n)
            ans.push_back(v);
        return;
    }
    for(int i = 0; i < n; i++)
    {
        bool res = true;
        for(auto j: pos)
        {
            if(j.second + ind - j.first == i || j.second - (ind - j.first) == i || j.second == i)
            {
                res = false;
                break;
            }
        }
        if(res)
        {
            s[i] = 'Q';
            pos.push_back({ind,i});
            v.push_back(s);
            s[i] = '.';
            findPos(ans, v, s, ind + 1, n, pos);
            v.pop_back();
            pos.pop_back();
        }
    }
}

//better (watch striver's approach on how to use hashing to optimize it more)
//you can also loop in back (upwards straight, left and right upwards diagonal and check if you find any queen there instead of using extra sapce to store indices of already visited queen)
//time: O(N!*N)
//space: O(3N) storage space and O(N) recursive space
vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> v;
    string queen = "";
    for(int i = 0; i < n; i++)
        queen += ".";
    for(int i = 0; i < n; i++)
    {
        vector<pair<int, int>> pos;
        pos.push_back({0, i});
        queen[i] = 'Q';
        v.push_back(queen);
        queen[i] = '.';
        findPos(ans, v, queen, 1, n, pos);
        v.pop_back();
        pos.pop_back();
    }
    return ans;
}