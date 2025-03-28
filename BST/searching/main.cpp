#include <bits/stdc++.h>

using namespace std;


class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

//recursive
//time: O(n)
//space: O(n)
TreeNode* searchBST(TreeNode* root, int val) {
    if(root == NULL) return NULL;
    if(root->val == val) return root;
    if(val > root->val){
        return searchBST(root->right, val);
    }
    else{
        return searchBST(root->left, val);
    }
}

//iterative
//time: O(n)
//space: O(1)
TreeNode* searchBST(TreeNode* root, int val) {
    while(root != NULL && root->val != val)
    {
        if(root->val > val) root = root->left;
        else root = root->right;
    }
    return root;
}