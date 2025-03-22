#include <bits/stdc++.h>

using namespace std;


//time: O(n)
//space: O(n)
vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    queue<TreeNode*> q;
    vector<int> temp;
    unordered_map<TreeNode*, TreeNode*> mp;
    unordered_set<TreeNode*> st;
    q.push(root);
    while(!q.empty())
    {
        TreeNode* node = q.front();
        q.pop();
        if(node->left){
            mp[node->left] = node;
            q.push(node->left);
        }
        if(node->right){
            mp[node->right] = node;
            q.push(node->right);
        }
    }
    q.push(target);
    while(!q.empty())
    {
        if(k == 0) break;
        int size = q.size();
        for(int i = 0; i < size; i++)
        {
            TreeNode* node = q.front();
            q.pop();
            if(node->left){
                if(st.find(node->left) == st.end()) q.push(node->left);
            }
            if(node->right){
                if(st.find(node->right) == st.end()) q.push(node->right);
            }
            if(mp.find(node) != mp.end() && st.find(mp[node]) == st.end()) q.push(mp[node]);
            st.insert(node);
        }
        k--;
    }
    while(!q.empty())
    {
        temp.push_back(q.front()->val);
        q.pop();
    }
    return temp;
}