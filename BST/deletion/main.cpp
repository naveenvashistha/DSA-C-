#include <bits/stdc++.h>

using namespace std;



//my solution
//time: O(n)
//space: O(1)
TreeNode* deleteNode(TreeNode* root, int key) {
    TreeNode* parent = NULL;
    TreeNode* node = root;
    //find the node to be deleted
    while(node)
    {
        if(key == node->val){
            break;
        }
        else if(key > node->val){
            parent = node;
            node = node->right;
        }
        else{
            parent = node;
            node = node->left;
        }
    }
    //if node doesnt exist
    if(node == NULL) return root;
    //if node exist, point right subtree of node to rightmost node of first element of left subtree of the node
    TreeNode* temp = node->right;
    if(node->left){
        TreeNode* t = node->left;
        while(t->right) t = t->right;
        t->right = temp;
        if(parent){
            if(parent->left == node) parent->left = node->left;
            else parent->right = node->left;
        }
        else return node->left;
    }
    else{
        if(parent){
            if(parent->left == node) parent->left = temp;
            else parent->right = temp;
        }
        else return node->right;
    }
    return root;
}