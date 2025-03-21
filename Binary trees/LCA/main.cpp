#include <bits/stdc++.h>

using namespace std;

//time: O(n)
//space: O(n)
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == NULL || root == p || root == q) return root;
    TreeNode* node1 = lowestCommonAncestor(root->left, p, q);
    TreeNode* node2 = lowestCommonAncestor(root->right, p, q);
    if(!node1 && !node2) return NULL;
    else if(node1 == NULL) return node2;
    else if(node2 == NULL) return node1;
    else return root; 
}