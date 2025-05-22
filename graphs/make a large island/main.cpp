#include <bits/stdc++.h>

using namespace std;


//time: O(row * col)
//space: O(row * col)
class Solution {
public:
    class disjoint{
    public:
    vector<int> rank, size, parent;
    disjoint(int n){
        //considering 1 based indexing
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for(int i = 0; i < n + 1; i++) parent[i] = i;
    }

    int findUParent(int u)
    {
        if(u == parent[u]) return u;
        return parent[u] = findUParent(parent[u]);
    }

    void unionByRank(int u, int v)
    {
        int p_u = findUParent(u);
        int p_v = findUParent(v);
        if(p_u == p_v) return;
        if(rank[p_u] < rank[p_v]){
            parent[p_u] = p_v;
        }
        else if(rank[p_v] < rank[p_u]){
            parent[p_v] = p_u;
        }
        else{
            parent[p_u] = p_v;
            rank[p_v]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int p_u = findUParent(u);
        int p_v = findUParent(v);
        if(p_u == p_v) return;
        if(size[p_u] <= size[p_v]){
            parent[p_u] = p_v;
            size[p_v] += size[p_u]; 
        }
        else if(size[p_v] < size[p_u]){
            parent[p_v] = p_u;
            size[p_u] += size[p_v];
        }
    }

};
    int largestIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int max_sum = INT_MIN;
        disjoint ds(row * col);
        vector<pair<int, int>> zeroes;
        int r[] = {-1, 1, 0, 0};
        int c[] = {0, 0, -1, 1};
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(grid[i][j] == 1){
                    for(int k = 0; k < 4; k++){
                        int nrow = i + r[k];
                        int ncol = j + c[k];
                        if(nrow >= 0 && ncol >= 0 && nrow < row && ncol < col && grid[nrow][ncol]){
                            int a = nrow * col + ncol;
                            int b = i * col + j;
                            ds.unionBySize(a, b);
                        }
                    }
                }
                else zeroes.push_back({i, j});
            }
        }
        for(auto i: zeroes)
        {
            unordered_set<int> s;
            int sum = 0;
            for(int k = 0; k < 4; k++){
                int nrow = i.first + r[k];
                int ncol = i.second + c[k];
                if(nrow >= 0 && ncol >= 0 && nrow < row && ncol < col && grid[nrow][ncol]){
                    int ind = nrow * col + ncol;
                    int p = ds.findUParent(ind);
                    if(s.find(p) == s.end()){
                        sum += ds.size[p];
                        s.insert(p);
                    }
                }
            }
            max_sum = max(max_sum, sum);
        }
        if(max_sum == INT_MIN) return row * col;
        return max_sum + 1;
    }
};