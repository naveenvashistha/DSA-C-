#include <bits/stdc++.h>

using namespace std;


void preorder(TreeNode<int>* node, vector<int>& boundary)
{
    if(node == NULL) return;
    if(node->left == NULL && node->right == NULL) boundary.push_back(node->data);
    preorder(node->left, boundary);
    preorder(node->right, boundary);
}

void leftB(TreeNode<int>* node, vector<int>& boundary)
{
    if(node->left != NULL || node->right != NULL) boundary.push_back(node->data);
    if(node->left) leftB(node->left, boundary);
    else if(node->right) leftB(node->right, boundary);
}

void rightB(TreeNode<int>* node, vector<int>& rightBoundary)
{
    if(node->right) rightB(node->right, rightBoundary);
    else if(node->left) rightB(node->left, rightBoundary);
    if(node->left != NULL || node->right != NULL) rightBoundary.push_back(node->data);
}

//time: O(n)
//space: O(n)
vector<int> traverseBoundary(TreeNode<int> *root)
{
	// Write your code here.
    vector<int> boundary;
    boundary.push_back(root->data);
    if(root->left) leftB(root->left, boundary);
    preorder(root, boundary);
    if(root->right) rightB(root->right, boundary);
    return boundary;
}
