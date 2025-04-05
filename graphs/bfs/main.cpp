#include <bits/stdc++.h>

using namespace std;


//time: O(n + 2e)
//space: O(n)
vector<int> bfs(vector<vector<int>> &adj) {
    // Code here
    queue<int> q;
    vector<int> ans;
    int visited[adj.size()] = {0};
    q.push(0);
    visited[0] = 1;
    while(!q.empty())
    {
        int temp = q.front();
        q.pop();
        ans.push_back(temp);
        for(int i: adj[temp]){
            if(!visited[i]){
                q.push(i);
                visited[i] = 1;
            }
        }
    }
    return ans;
}