#include <bits/stdc++.h>

using namespace std;

//inorder
//time: O((n)
//space: O(1)
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> inorder;
    TreeNode* curr = root;
    while(curr != NULL)
    {
        if(curr->left == NULL){
            inorder.push_back(curr->val);
            curr = curr->right;
        }
        else{
            TreeNode* prev = curr->left;
            while(prev->right && prev->right != curr) prev = prev->right;
            if(prev->right == NULL){
                prev->right = curr;
                curr = curr->left;
            } 
            else{
                prev->right = NULL;
                inorder.push_back(curr->val);
                curr = curr->right;
            }
        }
    }
    return inorder;
}

//preorder
//time: O((n)
//space: O(1)
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> preorder;
    TreeNode* curr = root;
    while(curr != NULL)
    {
        if(curr->left == NULL){
            preorder.push_back(curr->val);
            curr = curr->right;
        }
        else{
            TreeNode* prev = curr->left;
            while(prev->right && prev->right != curr) prev = prev->right;
            if(prev->right == NULL){
                prev->right = curr;
                preorder.push_back(curr->val);
                curr = curr->left;
            } 
            else{
                prev->right = NULL;
                curr = curr->right;
            }
        }
    }
    return inorder;
}