#include <bits/stdc++.h>

using namespace std;


class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> levelOrder(TreeNode* root) {
    queue<TreeNode*> q;
    vector<vector<int>> v;
    if(root == NULL) return v;
    q.push(root);
    while(!q.empty())
    {
        vector<int> temp;
        int size = q.size();
        while(size != 0)
        {
            TreeNode* node = q.front();
            temp.push_back(node->val);
            q.pop();
            if(node->left != NULL){
                q.push(node->left);
            }
            if(node->right != NULL){
                q.push(node->right);
            }
            size--;
        }
        v.push_back(temp);
    }
    return v;
}