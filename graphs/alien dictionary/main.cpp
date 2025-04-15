#include <bits/stdc++.h>

using namespace std;

//time: O(k + e) + O(dic.length())
//space: O(k)
string getAlienLanguage(vector<string> &dictionary, int k)
{
    // Write your code here.
    vector<vector<int>> adj(k);
    string ans;
    for(int i = 0; i < dictionary.size() - 1; i++)
    {
        string s1 = dictionary[i];
        string s2 = dictionary[i + 1];
        int s = min(s1.size(), s2.size());
        for(int j = 0; j < s; j++)
        {
            if(s1[j] != s2[j])
            {
                adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                break;
            }
        }
    }
    vector<int> indegree(k);
    queue<int> q;
    for(auto i: adj)
    {
        for(auto j: i) indegree[j]++;
    }
    for(int i = 0; i < k; i++)
    {
        if(indegree[i] == 0) q.push(i);
    }
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node + 'a');
        for(auto i: adj[node]){
            indegree[i]--;
            if(indegree[i] == 0) q.push(i);
        }
    }
    return ans;
}