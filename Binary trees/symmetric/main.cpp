#include <bits/stdc++.h>

using namespace std;

//time: O(n)
//space: O(n)
bool traverse(TreeNode* node1, TreeNode* node2)
{
    if(node1 == NULL && node2 == NULL) return true;
    if((node1 == NULL && node2 != NULL) || (node1 != NULL && node2 == NULL)) return false;
    if(node1->val != node2->val) return false;
    bool r1 = traverse(node1->left, node2->right);
    bool r2 = traverse(node1->right, node2->left);
    return r1 && r2;
}
bool isSymmetric(TreeNode* root) {
    return traverse(root->left, root->right);
}