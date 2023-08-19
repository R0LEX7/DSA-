// Balanced Binary tree -> A balanced binary tree, also referred to as a height-balanced binary tree, is defined as a binary tree in which the height of the left and right subtree of any node differ by not more than 1. (lh - rh <= 1)
#include "balanced_binary_tree.h"
#include <bits/stdc++.h>
int dfsDepth(Node* root){
    // base case
    if(root == NULL) return 0;

    int lh = dfsDepth(root->left);
    if(lh == -1) return -1;
    int rh = dfsDepth(root->right);
    if(rh == -1) return -1;

    if(abs(lh - rh )> 1) return -1;
    return 1 + max(lh, rh);
}

bool isBalanced(Node *root) {
    return dfsDepth(root) != -1;
}
