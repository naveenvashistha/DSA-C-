#include <bits/stdc++.h>

using namespace std;




//time: O(n)
//space: O(1)
int inOrderSuccessor(Node *root, Node *x) {
    // Your code here
    int successor = -1;
    while(root != NULL)
    {
        if(x->data < root->data){
            successor = root->data;
            root = root->left;
        }
        else
            root = root->right;
    }
    return successor;
}