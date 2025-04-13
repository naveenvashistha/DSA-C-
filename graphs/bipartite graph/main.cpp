#include <bits/stdc++.h>

using namespace std;


//time: O(2e + v)
//space: O(v)
bool dfs(int node, int color, vector<vector<int>>& graph, vector<int>& colors)
{
   colors[node] = color;
   for(int i: graph[node])
   {
      if(colors[i] == color) return false;
      else if(colors[i] == -1){
            bool res = dfs(i, !color, graph, colors);
            if(!res) return res;
      }
   }
   return true;
}
bool isBipartite(vector<vector<int>>& graph) {
   vector<int> colors(graph.size(), -1);
   for(int i = 0; i < graph.size(); i++)
   {
      if(colors[i] == -1)
      {
            bool res = dfs(i, 0, graph, colors);
            if(!res) return res;
      }
   }
   return true;
}