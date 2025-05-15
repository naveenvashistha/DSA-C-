#include <bits/stdc++.h>

using namespace std;


//time: O(n)
//space: O(2*(maxrow + maxcol))
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
    int removeStones(vector<vector<int>>& stones) {
        int maxrow = 0;
        int maxcol = 0;
        for(auto i: stones)
        {
            maxrow = max(maxrow, i[0]);
            maxcol = max(maxcol, i[1]);
        }
        disjoint ds(maxrow + maxcol + 1);
        for(auto i: stones)
        {
            int u = i[0];
            int v = i[1] + maxrow + 1;
            ds.unionBySize(u, v);
        }
        unordered_set<int> st;
        for(int i = 0; i < ds.parent.size(); i++)
        {
            int Uparent = ds.findUParent(i);
            if(Uparent != i) st.insert(Uparent);
        }
        return stones.size() - st.size();
    }
};