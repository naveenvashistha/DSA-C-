#include <bits/stdc++.h>

using namespace std;



//recursive
//time: O(n)
//space: O(h)
TreeNode* insertIntoBST(TreeNode* root, int val) {
    if(root == NULL) return new TreeNode(val);
    if(val > root->val) root->right = insertIntoBST(root->right, val);
    else root->left = insertIntoBST(root->left, val);
    return root;
}

//iterative
//time: O(n)
//space: O(1)
TreeNode* insertIntoBST(TreeNode* root, int val) {
    if(root == NULL) return new TreeNode(val);
    TreeNode* rooty = root;
    while(true)
    {
        if(val > root->val){
            if(root->right != NULL) root = root->right;
            else{
                root->right = new TreeNode(val);
                break;
            }
        }
        else{
            if(root->left != NULL) root = root->left;
            else{
                root->left = new TreeNode(val);
                break;
            }
        }
    }
    return rooty;
}