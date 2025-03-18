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
//space: O(n)
int diameter(TreeNode* node, int &w)
{
    if(node == NULL) return 0;
    int h1 = diameter(node->left, w);
    int h2 = diameter(node->right, w);
    w = max(w, h1 + h2);
    return 1 + max(h1, h2);
}
int diameterOfBinaryTree(TreeNode* root) {
    int w = 0;
    diameter(root, w);
    return w;
}