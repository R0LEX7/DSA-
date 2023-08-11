#include<iostream>
using namespace std;


class Node{
    public: 
    int data;
    Node* prev; 
    Node* next;

    Node(int data ){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    } 
};

void print(Node* head){
    Node* temp = head;
    cout<<"[ ";
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    };
    cout<<"]";
    cout<<endl;
};

void insertAtHead(Node* &head , int data){
    Node * newNode = new Node(data);
    head->prev = newNode;
    newNode->next = head;
    newNode->prev = NULL;
    head = newNode;
    print(head);
};

void insertAtTail(Node* &head , int data){
    Node * newNode = new Node(data);
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    };
    temp->next = newNode;
    newNode->prev = temp;
    print(head);
};

void insertAtPosition(Node * &head,int pos , int data){
    // if position is head/start
    if(pos == 1){
        insertAtHead(head,data);
        return;
    }
    Node * newNode = new Node(data);
    Node * temp = head;
    int count = 1;

    while(count < pos-1){
        count++;
        temp = temp->next;    
    };
    // if it is found that pos is tail
    if(temp->next == NULL){
        insertAtTail(head , data);
        return;
    }
    Node * nextNode = temp->next;
    newNode->next = nextNode;
    temp->next = newNode;
    newNode->prev = temp;
    nextNode->prev = newNode;
    print(head);
};

void deleteAtHead(Node * &head){
    Node * temp = head;
    Node * nextHead = temp->next;
    nextHead->prev = NULL;
    head = nextHead;
    delete(temp);
    print(head);
};

void deleteAtTail(Node* &head){
    Node * temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    };
    Node * prevNode = temp->prev;
    prevNode->next = NULL;
    delete(temp);
    print(head);
};

void deleteAtPosition(Node* &head , int pos){
    if(pos == 1){
        deleteAtHead(head);
        return;
    };
     Node * temp = head;
    int count = 1;

    while(count < pos){
        count++;
        temp = temp->next;    
    };
    if(temp->next == NULL){
        deleteAtTail(head);
        return;
    }
    Node * prevNode = temp->prev;
    Node * nextNode = temp->next;
    prevNode->next = nextNode;
    nextNode->prev = prevNode;
    delete(temp);
    print(head);
}

int main(){

    Node* n1 = new Node(100);
    insertAtHead(n1 ,50);
    insertAtTail(n1 ,100);
    insertAtTail(n1 ,200);
    insertAtTail(n1 ,150);
    insertAtTail(n1 ,200);
    insertAtTail(n1 ,250);
    insertAtTail(n1 ,400);
    insertAtPosition(n1 , 8 , 300);
    insertAtPosition(n1 , 9 , 350);




    return 0;
}