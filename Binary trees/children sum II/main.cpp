#include <bits/stdc++.h>

using namespace std;


//time: O(n)
//space: O(n)
int isSumProperty(Node *root)
{
    // Add your code here
    if(root == NULL || (!root->left && !root->right)) return 1;
    int d = 0;
    if(root->left) d += root->left->data;
    if(root->right) d += root->right->data;
    if(d == root->data)
    {
        int r1 = isSumProperty(root->left);
        int r2 = isSumProperty(root->right);
        return r1 && r2;
    }
    return 0;
}