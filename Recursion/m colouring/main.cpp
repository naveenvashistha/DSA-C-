#include <bits/stdc++.h>

using namespace std;

bool assignColor(vector<vector<int>> &adj, int v, int m);
bool graphColoring(int n, vector<pair<int, int>>& edges, int m);

int main()
{
    vector<pair<int, int>> edges = {{0,1}, {1,2}, {2, 3}, {3, 0}, {0, 2}};
    cout << graphColoring(4, edges, 3) << endl;
}

bool assignColor(vector<vector<int>> &adj, int v, int m)
{
    if(v == adj.size())
    {
        return true;
    }
    bool res = false;
    for(int i = 1; i <= m; i++)
    {
        bool r = false;
        for(int j = 0; j < v; j++)
        {
            if(adj[v][j] == -1 && adj[j][j] == i)
            {
                r = true;
                break;
            }
        }
        if(r == true) continue;
        adj[v][v] = i;
        res = assignColor(adj, v + 1, m);
        adj[v][v] = 0;
        if(res == true) return res;
    }
    return res;
}

//orgasmic
//time: O(m^n * n)
//space: O(n^2) storage and O(n) recursive
bool graphColoring(int n, vector<pair<int, int>>& edges, int m) {
    // code here
    if(m >= n) return true;
    vector<vector<int>> adj(n, vector<int>(n, 0));
    for(auto i: edges)
    {
        adj[i.first][i.second] = -1;
        adj[i.second][i.first] = -1;
    }
    bool res = assignColor(adj, 0, m);
    return res;
}