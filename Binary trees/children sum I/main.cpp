#include <bits/stdc++.h>

using namespace std;


//time: O(n)
//space: O(n)
void changeTree(BinaryTreeNode < int > * root) {
    // Write your code here.
    if(root == NULL) return;
    int d1 = 0, d2 = 0;
    if(root->left) d1 = root->left->data;
    if(root->right) d2 = root->right->data;
    if(root->data > d1 + d2)
    {
        if(root->left) root->left->data = root->data;
        if(root->right) root->right->data = root->data;
    }
    changeTree(root->left);
    changeTree(root->right); 
    d1 = 0;
    d2 = 0;
    if(root->left) d1 = root->left->data;
    if(root->right) d2 = root->right->data;
    if(root->left != NULL || root->right != NULL) root->data = d1 + d2;
}  