#include <bits/stdc++.h>

using namespace std;


//time: O(Q)
//space: O(n*m)
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
vector<int> numOfIslandsII(int n, int m, vector<vector<int>> &q){
	// Write your code here.
	vector<vector<int>> vec(n, vector<int>(m, 0));
	vector<vector<int>> visited(n, vector<int>(m, 0));
	disjoint ds(n * m);
	vector<int> ans;
	int cnt = 0;
	int r[] = {0, 0, 1, -1};
	int c[] = {1, -1, 0, 0};
	for(auto i: q)
	{
		int row = i[0];
		int col = i[1];
		if(!visited[row][col])
		{
			visited[row][col] = 1;
			vec[row][col] = 1;
			cnt++;
			for(int j = 0; j < 4; j++)
			{
				int nrow = row + r[j];
				int ncol = col + c[j];
				if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && vec[nrow][ncol]){
					int indice1 = nrow * m + ncol;
					int indice2 = row * m + col;
					if(ds.findUParent(indice1) != ds.findUParent(indice2)){
						ds.unionBySize(indice2, indice1);
						cnt--;
					}
				}
			}
		}
		ans.push_back(cnt);
	}
	return ans;
}