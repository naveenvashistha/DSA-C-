#include <bits/stdc++.h>

using namespace std;


vector<int> topView(Node *root) {
    // code here
    map<int, int> mp;
    queue<pair<Node*, int>> q;
    vector<int> temp;
    q.push({root, 0});
    while(!q.empty())
    {
        pair<Node*, int> t = q.front();
        q.pop();
        if(mp.find(t.second) == mp.end()) mp[t.second] = t.first->data;
        if(t.first->left) q.push({t.first->left, t.second - 1});
        if(t.first->right) q.push({t.first->right, t.second + 1});
    }
    for(auto i: mp)
    {
        temp.push_back(i.second);
    }
    return temp;
}