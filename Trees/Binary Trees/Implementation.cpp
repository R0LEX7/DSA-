#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data ;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};


// preorder traversal(root left right)

void iterativePreOrder(Node* root){

    stack<Node*> st;
    st.push(root);

    while(!st.empty()){
        Node* temp= st.top();
        st.pop();
        cout<<temp->data<<" ";
        if(temp->right != NULL) st.push(temp->right);
        if(temp->left != NULL) st.push(temp->left);
    }  
}

void preOrder(Node *root){
    // base case
    if(root == NULL ){
        return;
    }

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

// postorder traversal (left right root)
void iterativePostOrder(Node* root){

    stack<Node*> st1, st2;
    st1.push(root);

    while(!st1.empty()){
        Node* temp= st1.top();
        st1.pop();
        st2.push(temp);

        if(temp->left != NULL) st1.push(temp->left);
        if(temp->right != NULL) st1.push(temp->right);
    }  

    while(!st2.empty()){
        Node* temp= st2.top();
        cout<<temp->data<<" ";
        st2.pop(); 
    }
}
void postOrder(Node *root){
    // base case
    if(root == NULL ){
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

// inorder traversal (left root right)

vector<int> iterativeInOrder(Node *root){

    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    
    stack<Node*> st;
    Node* node = root;
    while(1){
        if(node != NULL){
            st.push(node);
            node = node->left;
        }else{
            if(st.empty() == true) break;
            node = st.top();
            st.pop();
            ans.push_back(node->data);
            node = node->right;
        }
    }
    return ans;
}

void inOrder(Node *root){
    // base case
    if(root == NULL ){
        return;
    }

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

// level order traversal 

vector<vector<int>> levelOrder(Node *root){
    vector<vector<int>> ans;

    if(root == NULL){
        return ans;
    }

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        vector<int> level;
        for(int i = 0; i < size; i++){
            Node* p = q.front();
            q.pop();
            if(p->left != NULL) q.push(p->left);
            if(p->right != NULL) q.push(p->right);
            level.push_back(p->data);
        }
        ans.push_back(level);
        
    }
    return ans;
}

// maximum depth of binary tree;

int maxDepth(Node* root){
    // base case
    if(root == NULL) return 0;

    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);
    
    return 1 + max(lh, rh);
}


// // Balanced Binary tree -> A balanced binary tree, also referred to as a height-balanced binary tree, is defined as a binary tree in which the height of the left and right subtree of any node differ by not more than 1. (lh - rh <= 1)

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

// Diameter of the Binary tree -> The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root .

int depth(Node *root , int& diameter) {
    // base case
    if(root == NULL) return 0;
    int lh = depth(root->left, diameter);
    int rh = depth(root->right, diameter);

    diameter = max(diameter, lh+rh);
    return 1+ max(lh,rh);
}

int diameterOfBinaryTree(Node *root){
    int diameter = 0;
    depth(root, diameter); 
    return diameter;
}

int main(){
    Node* a = new Node(20);
    Node* b = new Node(5);
    Node* c = new Node(4);
    Node* d = new Node(100);
    Node* e = new Node(500);
    Node* f = new Node(80);
    Node* g = new Node(320);
    
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;
/*
    cout<<"XXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
    cout<<"PreOrder traversal"<<endl;
    preOrder(a);
    cout<<endl;
    cout<<"XXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
    cout<<"PostOrder traversal"<<endl;
    postOrder(a);
    cout<<endl;
    cout<<"XXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
    cout<<"InOrder traversal"<<endl;
    inOrder(a);
    cout<<endl;
    cout<<"XXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
    vector<vector<int>> ans = levelOrder(a);

    for(int i=0;i<ans.size();i++){
        // cout<<endl;
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        
    }

    cout<<endl;
    cout<<"XXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
    cout<<"Iterative preorder"<<endl;
    iterativePreOrder(a);

    cout<<endl;
    cout<<"XXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
    cout<<"Iterative postorder"<<endl;
    iterativePostOrder(a);

    cout<<endl;
    cout<<"XXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
    cout<<"Iterative inorder"<<endl;
    vector<int> inorder = iterativeInOrder(a);

    for(auto x : inorder){
        cout<<x<<" ";
    } 
    */

    int h = maxDepth(a);
    cout<<"Max depth: "<<h<<endl;  
    if(isBalanced(a)){
        cout<<"Balanced Binary Tree: "<<endl;
    }else{
        cout<<"Unbalanced Binary Tree: "<<endl;
    }

    cout<<"Diameter of Binary Tree: "<<diameterOfBinaryTree(a)<<endl;

    return 0;
}