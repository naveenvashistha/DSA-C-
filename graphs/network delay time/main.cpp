#include <bits/stdc++.h>

using namespace std;

//using dfs
//time: O(elogv + v)
//space: O(v)
int networkDelayTime(vector<vector<int>>& times, int n, int k) {
	priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> pq;
	vector<vector<pair<int, int>>> adj(n + 1);
	for(auto i: times) adj[i[0]].push_back({i[1], i[2]});
	vector<int> dist(n + 1, INT_MAX);
	pq.push({0, k});
	dist[k] = 0;
	while(!pq.empty())
	{
		int node = pq.top().second;
		int d = pq.top().first;
		pq.pop();
		for(auto i: adj[node])
		{
			if(dist[i.first] > d + i.second){
				pq.push({d + i.second, i.first});
				dist[i.first] = d + i.second;
			}
		}
	}
	int maxx = INT_MIN;
	for(int i = 1; i <= n; i++)
	{
		if(dist[i] == INT_MAX) return -1;
		maxx = max(maxx, dist[i]);
	}
	return maxx;
}