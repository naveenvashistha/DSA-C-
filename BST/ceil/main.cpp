#include <bits/stdc++.h>

using namespace std;




//time: O(n)
//space: O(1)
int findCeil(Node* root, int input) {
    int successor = -1;
    while(root != NULL)
    {
        if(input == root->data) return input;
        if(input > root->data){
            root = root->right; 
        }
        else{
            successor = root->data;
            root = root->left;
        }
    }
    return successor;
}