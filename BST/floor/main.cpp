#include <bits/stdc++.h>

using namespace std;




//time: O(n)
//space: O(1)
int floor(Node* root, int x) {
    // Code here
    int predecessor = -1;
    while(root)
    {
        if(x == root->data) return x;
        if(x > root->data){
            predecessor = root->data;
            root = root->right;
        }
        else{
            root = root->left;
        }
    }
    return predecessor;
}