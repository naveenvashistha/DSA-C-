#include <bits/stdc++.h>

using namespace std;

//using dfs
//time: O(e)
//space: O(v)
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
	vector<vector<pair<int, int>>> adj(n);
	for(auto i: flights) adj[i[0]].push_back({i[1], i[2]});
	queue<vector<int>> q;
	vector<int> dist(n, INT_MAX);
	dist[src] = 0;
	q.push({-1, src, 0});
	while(!q.empty())
	{
		int steps = q.front()[0];
		int node = q.front()[1];
		int d = q.front()[2];
		q.pop();
		if(node == dst) continue;
		for(auto i: adj[node])
		{
			if(dist[i.first] > d + i.second && steps + 1 <= k){
				dist[i.first] = d + i.second;
				q.push({steps + 1, i.first, d + i.second});
			}
		}
	}
	if(dist[dst] == INT_MAX) return -1;
	return dist[dst]; 
}