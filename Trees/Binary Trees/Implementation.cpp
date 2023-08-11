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

// void preOrder(Node* root){

//     Node* temp= root;
    
//         cout<<temp->data<<endl;
//     while(temp->left!=  NULL || temp->right!= NULL){

//         cout<<temp->left->data<<endl;
//         cout<<temp->right->data<<endl;
//         temp = 
//     }
// }

// preorder traversal(root left right)
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
        cout<<endl;
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        
    }

    return 0;
}