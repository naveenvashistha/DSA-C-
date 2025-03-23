#include <bits/stdc++.h>

using namespace std;


//time: O((logn)^2)
//space: O(n)
int calcLeftHeight(TreeNode* node)
{
    if(node == NULL) return 0;
    return 1 + calcLeftHeight(node->left);
}
int calcRightHeight(TreeNode* node)
{
    if(node == NULL) return 0;
    return 1 + calcRightHeight(node->right);
}
int countNodes(TreeNode* root) {
    if(root == NULL) return 0;
    int lh, rh;
    int h1 = calcLeftHeight(root);
    int h2 = calcRightHeight(root);
    if(h1 == h2){
        lh = pow(2, h1 - 1) - 1;
        rh = lh;
    }
    else{
        lh = countNodes(root->left);
        rh = countNodes(root->right);
    }
    return 1 + lh + rh; 
}