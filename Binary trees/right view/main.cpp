#include <bits/stdc++.h>

using namespace std;

//iterative
//time: O(n)
//space: O(n)
vector<int> rightSideView(TreeNode* root) {
    queue<TreeNode*> q;
    vector<int> temp;
    if(root == NULL) return temp;
    q.push(root);
    while(!q.empty())
    {
        int size = q.size();
        TreeNode* node;
        for(int i = 0; i < size; i++){
            node = q.front();
            q.pop();
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        temp.push_back(node->val);
    }
    return temp;
}

//recursive
//time: O(n)
//space: O(n)
void traversal(TreeNode* node, int level, vector<int>& temp)
{
    if(node == NULL) return;
    if(temp.size() == level) temp.push_back(node->val);
    traversal(node->right, level + 1, temp);
    traversal(node->left, level + 1, temp);
}
vector<int> rightSideView(TreeNode* root) {
    vector<int> temp;
    traversal(root, 0, temp);
    return temp;
}