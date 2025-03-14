#include <bits/stdc++.h>

using namespace std;


class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

void preorder(TreeNode *root, vector<int> &pre)
{
    if(root == NULL) return;
    pre.push_back(root->data);
    preorder(root->left, pre);
    preorder(root->right, pre);
}
void postorder(TreeNode *root, vector<int> &post)
{
    if(root == NULL) return;
    postorder(root->left, post);
    postorder(root->right, post);
    post.push_back(root->data);
}
void inorder(TreeNode *root, vector<int> &ino)
{
    if(root == NULL) return;
    inorder(root->left, ino);
    ino.push_back(root->data);
    inorder(root->right, ino);
}
vector<vector<int>> getTreeTraversal(TreeNode *root){
    // Write your code here.
    vector<int> pre;
    vector<int> post;
    vector<int> ino;
    preorder(root, pre);
    postorder(root, post);
    inorder(root, ino);
    vector<vector<int>> v = {ino, pre, post};
    return v;
}