#include <bits/stdc++.h>

using namespace std;

//using priority queue
//time: O(N+E) + O(E*4ɑ) + O(N*(ElogE + E))
//space: O(N)
class Solution {
public:
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> ans;
        disjoint ds(accounts.size());
        unordered_map<string, int> email;
        for(int account = 0; account < accounts.size(); account++)
        {
            for(int node = 1; node < accounts[account].size(); node++)
            {
                string n = accounts[account][node];
                if(email.find(n) == email.end()) email[n] = account;
                else{
                    ds.unionBySize(account, email[n]);
                } 
            }
        }
        unordered_map<int, vector<string>> temp;
        for(auto i: email)
        {
            int parent = ds.findUParent(i.second);
            temp[parent].push_back(i.first);
        }
        for(auto i: temp){
            sort(i.second.begin(), i.second.end());
            vector<string> b;
            b.push_back(accounts[i.first][0]); 
            for(auto j: i.second) b.push_back(j);
            ans.push_back(b);
        }
        return ans;
    }
};