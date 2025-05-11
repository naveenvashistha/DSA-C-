#include <bits/stdc++.h>

using namespace std;


//time: O(ElogE)
//space: O(V) + O(E)
int spanningTree(int V, vector<vector<int>> adj[]) {
    // code here
    priority_queue<pair<int, int>,vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int sum = 0;
    pq.push({0, 0});
    vector<int> visited(V, 0);
    while(!pq.empty())
    {
        pair<int, int> p = pq.top();
        pq.pop();
        if(!visited[p.second]){
            sum += p.first;
            visited[p.second] = 1;
            for(auto j: adj[p.second])
            {
                if(!visited[j[0]]) pq.push({j[1], j[0]});
            }
        }
    }
    return sum;
}