#include <bits/stdc++.h>

using namespace std;




//time: O(h)
//space: O(h)
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == p || root == q) return root;
    TreeNode* node1;
    if(p->val < root->val && q->val < root->val)
        node1 = lowestCommonAncestor(root->left, p, q);
    else if(p->val > root->val && q->val > root->val)
        node1 = lowestCommonAncestor(root->right, p, q);
    else node1 = root;
    return node1;
}