#include <bits/stdc++.h>

using namespace std;

//time: O(v + e)
//space: O(v)
bool dfs(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int> pathvis, stack<int>& st)
{
    visited[node] = 1;
    pathvis[node] = 1;
    for(auto i: adj[node])
    {
        if(!visited[i]){
            bool res = dfs(i, adj, visited, pathvis, st);
            if(res) return true;
        }
        else if(pathvis[i]) return true;
    }
    pathvis[node] = 0;
    st.push(node);
    return false;
}
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> ans;
    vector<int> visited(numCourses);
    vector<int> pathvis(numCourses);
    vector<vector<int>> adj(numCourses);
    stack<int> st;
    for(auto i: prerequisites) adj[i[1]].push_back(i[0]);
    for(int i = 0; i < numCourses; i++)
    {
        if(!visited[i]){
            bool res = dfs(i, adj, visited, pathvis, st);
            if(res) return ans;
        }
    }
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}