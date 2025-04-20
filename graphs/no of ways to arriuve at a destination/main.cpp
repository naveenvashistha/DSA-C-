#include <bits/stdc++.h>

using namespace std;

//my solution (cause TLE)
int countPaths(int n, vector<vector<int>>& roads) {
	const int mod = 1e12 + 7;
	priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> pq;
	vector<vector<pair<int, int>>> adj(n);
	for(auto i: roads){
		adj[i[0]].push_back({i[1], i[2]});
		adj[i[1]].push_back({i[0], i[2]});
	}
	vector<int> dist(n, INT_MAX);
	pq.push({0, 0});
	dist[0] = 0;
	int min_dist = INT_MAX, count = 0;
	while(!pq.empty())
	{
		int node = pq.top().second;
		int d = pq.top().first;
		cout << "current: " << node << endl; 
		pq.pop();
		if(node == n - 1){
			if(d <= min_dist){
				min_dist = d;
				count = (count + 1) % mod;
			}
			continue;
		}
		for(auto i: adj[node])
		{
			if(dist[i.first] >= d + i.second){
				cout << "pushing: " << i.first << endl;
				pq.push({d + i.second, i.first});
				dist[i.first] = d + i.second;
			}
		}
	}
	return count;
}

//orgasmic
//time: O(elogv)
//space: O(v)
int countPaths(int n, vector<vector<int>>& roads) {
	const int mod = 1e9 + 7;
	priority_queue<pair<long,long>, vector<pair<long,long>> , greater<pair<long,long>>> pq;
	vector<vector<pair<long, long>>> adj(n);
	for(auto i: roads){
		adj[i[0]].push_back({i[1], i[2]});
		adj[i[1]].push_back({i[0], i[2]});
	}
	vector<long long> dist(n, LLONG_MAX);
	vector<long long> ways(n, 0);
	pq.push({0, 0});
	ways[0] = 1;
	dist[0] = 0;
	while(!pq.empty())
	{
		long long node = pq.top().second;
		long long d = pq.top().first; 
		pq.pop();
		for(auto i: adj[node])
		{
			if(dist[i.first] > d + i.second){
				pq.push({d + i.second, i.first});
				dist[i.first] = d + i.second;
				ways[i.first] = ways[node];
			}
			else if(dist[i.first] == d + i.second)
			{
				ways[i.first] = (ways[node] + ways[i.first]) % mod;
			}
		}
	}
	return ways[n - 1] % mod;
}