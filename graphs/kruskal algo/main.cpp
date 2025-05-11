#include <bits/stdc++.h>

using namespace std;

class disjoint{
    vector<int> rank, size, parent;
    public:
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

    int unionBySize(int u, int v, int wt)
    {
        int p_u = findUParent(u);
        int p_v = findUParent(v);
        if(p_u == p_v) return 0;
        if(size[p_u] <= size[p_v]){
            parent[p_u] = p_v;
            size[p_v] += size[p_u];
            return wt;
        }
        else if(size[p_v] < size[p_u]){
            parent[p_v] = p_u;
            size[p_u] += size[p_v];
            return wt;
        }
    }

};

//time: O(eloge) + O(e*4α*2)
//space: O(e) + O(2n)
int kruskalsMST(int V, vector<vector<int>> &edges) {
    // code here
    vector<vector<int>> e;
    for(auto i: edges)
    {
        int wt = i[2];
        int u = i[0];
        int v = i[1];
        e.push_back({wt, u, v});
    }
    sort(e.begin(), e.end());
    int sum = 0;
    disjoint d(V);
    for(auto i: e)
    {
        int u = i[1];
        int v = i[2];
        int wt = i[0];
        sum += d.unionBySize(u, v, wt);
    }
    return sum;
}