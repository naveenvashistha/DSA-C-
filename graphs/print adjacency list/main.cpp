#include <bits/stdc++.h>

using namespace std;

//time: O(n)
//space: O(n)
vector<vector<int>> printGraph(int V, vector<pair<int, int>>& edges) {
    // Code here
    vector<vector<int>> al(V);
    for(auto i: edges)
    {
        al[i.first].push_back(i.second);
        al[i.second].push_back(i.first);
    }
    return al;
}