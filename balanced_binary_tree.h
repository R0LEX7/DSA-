// balanced_binary_tree.h
#ifndef BALANCED_BINARY_TREE_H
#define BALANCED_BINARY_TREE_H

struct Node {
    int data;
    Node* left;
    Node* right;
};

bool isBalanced(Node* root);

#endif
