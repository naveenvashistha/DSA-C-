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

//optimal
//time: O(n)
//spae: O(n)
int height(TreeNode* node)
    {
        if(node == NULL) return 0;
        int h1 = height(node->left);
        int h2 = height(node->right);
        if(abs(h1 - h2) > 1 || h1 < 0 || h2 < 0) return -1;
        return 1 + max(h1, h2);
    }
bool isBalanced(TreeNode* root) {
    if(root == NULL) return true;
    int h = height(root);
    if(h == -1) return false;
    return true;
}