#include <bits/stdc++.h>

using namespace std;

//using dfs
//time: O(v + e)
//space: O(v)
bool dfs(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& pathvis)
{
	visited[node] = 1;
	pathvis[node] = 1;
	for(auto i: adj[node])
	{
		if(!visited[i]){
			bool res = dfs(i, adj, visited, pathvis);
			if(res) return true;
		}
		else if(pathvis[i]) return true;
	}
	pathvis[node] = 0;
	return false;
}
vector<int> eventualSafeNodes(vector<vector<int>>& graph){
	vector<int> ans;
	vector<int> visited(graph.size());
	vector<int> pathvis(graph.size());
	for(int i = 0; i < graph.size(); i++)
	{
		if(!visited[i]){
			dfs(i, graph, visited, pathvis);
		}
	}
	for(int i = 0; i < graph.size(); i++)
	{
		if(!pathvis[i]) ans.push_back(i);
	}
	return ans;
}


//using bfs
//time: O(vlogv) + O(v + e)
//space: O(v)
vector<int> eventualSafeNodes(vector<vector<int>>& graph){
	vector<int> ans;
	queue<int> q;
	vector<int> indegree(graph.size());
	vector<vector<int>> graphOut(graph.size());
	for(int i = 0; i < graph.size(); i++)
	{
		for(auto j: graph[i]) graphOut[j].push_back(i);
	}
	for(auto i: graphOut)
	{
		for(auto j: i) indegree[j]++;
	}
	for(int i = 0; i < graph.size(); i++)
	{
		if(indegree[i] == 0) q.push(i);
	}
	while(!q.empty())
	{
		int node = q.front();
		q.pop();
		ans.push_back(node);
		for(auto i: graphOut[node])
		{
			indegree[i]--;
			if(indegree[i] == 0) q.push(i);
		}
	}
	sort(ans.begin(), ans.end());
	return ans;
}