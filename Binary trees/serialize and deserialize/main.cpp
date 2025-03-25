#include <bits/stdc++.h>

using namespace std;


//time: O((n)
//space: O(n)
string serialize(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    string s;
    while(!q.empty())
    {
        TreeNode* node = q.front();
        q.pop();
        if(node == NULL) s += "#,";
        else{
            s += to_string(node->val) + ",";
            q.push(node->left);
            q.push(node->right);
        }
    }
    return s;
}

// Decodes your encoded data to tree.
//time: O((n)
//space: O(n)
TreeNode* deserialize(string data) {
    stringstream s(data);
    string str;
    getline(s, str, ',');
    if(str == "#") return NULL;
    TreeNode* root = new TreeNode(stoi(str));
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode* node = q.front();
        q.pop();
        getline(s, str, ',');
        if(str != "#"){
            node->left = new TreeNode(stoi(str));
            q.push(node->left);
        }
        getline(s, str, ',');
        if(str != "#"){
            node->right = new TreeNode(stoi(str));
            q.push(node->right);
        }
    }
    return root;
}