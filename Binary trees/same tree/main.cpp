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
bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p == NULL && q == NULL) return true;
    else if((p == NULL && q != NULL) || (p != NULL && q == NULL)) return false;

    bool res1, res2;
    if(p->val == q->val)
    {
        res1 = isSameTree(p->left, q->left);
        res2 = isSameTree(p->right, q->right);
    }
    else return false;

    return res1 && res2;
}