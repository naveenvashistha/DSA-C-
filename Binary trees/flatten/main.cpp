#include <bits/stdc++.h>

using namespace std;

//my solution
//time: O(n)
//space: O(n)
void flatten(TreeNode* root) {
    if(root == NULL) return;
    flatten(root->left);
    flatten(root->right);
    TreeNode* l = root->left;
    while(l != NULL && l->right != NULL) l = l->right;
    if(l != NULL){
        l->right = root->right;
        if(root->left) root->right = root->left;
        root->left = NULL;
    }
}

//orgasmic
//time: O(n)
//space: O(n)
TreeNode* prev = NULL;
void flatten(TreeNode* root) {
    if(root == NULL) return;
    flatten(root->left);
    flatten(root->right);
    root->right = prev;
    root->left = NULL;
    prev = root;
}