#include <bits/stdc++.h>

using namespace std;

//time: O(v + e)
//space: O(v)
vector<int> topologicalSort(vector<pair<int,int>>& edges, int N, int M)
{
	vector<int> ans;
	queue<int> q;
	vector<int> indegree(N + 1, 0);
	vector<vector<int>> adj(N + 1);
	for(auto i: edges) adj[i.first].push_back(i.second);
	for(auto i: adj)
	{
		for(auto j: i) indegree[j]++;
	}
	for(int i = 1; i < N + 1; i++){
		if(indegree[i] == 0) q.push(i);
	}
	while(!q.empty())
	{
		int node = q.front();
		q.pop();
		ans.push_back(node);
		for(auto i: adj[node])
		{
			indegree[i]--;
			if(indegree[i] == 0) q.push(i);
		}
	}
	return ans;
} 
