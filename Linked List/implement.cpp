#include<iostream>
#include<map>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    };
};

    void insertAtHead(Node* &head , int data){
        // create a new node
        Node * temp = new Node(data);
        temp->next = head;
        head = temp;
    };

//     void insertAtTail(Node* &head , int data){

//         Node * newNode = new Node(data);
//         if(head == NULL){
//             head = newNode;
//         };
//         // create a new node
//         Node * temp = head;
//         while(temp->next != NULL){
//             temp = temp->next;
//         };

//         temp->next = newNode;
//         newNode->next = NULL;


//     };

//     void insertAtMiddle(Node* &head , int pos , int data){
//         if(pos == 1){
//             insertAtHead(head , data);
//             return;
//         };
//         // create a new node
//         Node * temp = head;
//         int count = 1;

//         while(count < pos-1){
//             temp = temp->next;
//             count++; 
//         };

//         if(temp->next == NULL){
//             insertAtTail(head , data);
//             return;
//         }

//         Node * newNode = new Node(data);
//         newNode->next = temp->next;
//         temp->next = newNode;    
//     };

    void print(Node* &head){
        Node * temp = head;
        cout<<"Head -> ";
        while(temp != NULL){
            // cout<<"[ "<<temp->data<<" "<<temp->next<<" ]"<<" ";
            cout<<temp->data<<" ";
            temp = temp->next;
        };
    };

//     Node* getTail(Node * head){
//         Node * temp = head;
//         while(temp->next != NULL){
//             // cout<<"[ "<<temp->data<<" "<<temp->next<<" ]"<<" ";
//             temp = temp->next;
//         };
//         return temp;
//     }

//     void deleteAtHead(Node *& head){
//         Node * temp = head;
//         head = head->next;
//         delete temp;
//     };

//     void deleteAtPosition(Node * &head , int pos){

//         if(pos == 1){
//             deleteAtHead(head);
//             return;
//         }

//         Node * temp = head;
//         int count = 1;
//         while(count < pos-1){
//             temp = temp->next;
//             count++; 
//         };

//         Node* deleteNode = temp->next;
//         temp->next =  deleteNode->next;

//     };

//     void deleteAtTail(Node *& head){
//         if(head == NULL){
//             cout<<"Linked list is empty"<<endl;
//         };
//         // create a new node
//         Node * temp = head;
//         // int count = 1;
//         Node * prev = NULL;
//         while(temp->next != NULL){
//             prev = temp;
//             temp = temp->next;
//         };
//         prev->next = NULL ;
//         delete temp;
//     };

//     bool detectCycle(Node* head){
//     if(head == NULL) return false;
//     Node* curr = head;
//     map<Node* , bool> visited;

//     while(curr!=NULL){
//         if(visited[curr] == true){
//             return true;
//         };
//         visited[curr] = true;
//         curr = curr->next;
//     }
//     return false;
// }

// Node* floydCycleDetection(Node * head){
//     if(head == NULL) return NULL;
//     Node * slow = head;
//     Node * fast = head;

//     while(fast->next != NULL){
//         fast = fast->next;
//         if(fast->next != NULL){
//             fast = fast->next;
//         };
//         slow = slow->next;
//         if(slow == fast){
//             return fast;
//         }
//     }

//     return NULL;
// }

// Node* getStartingPoint(Node * head){
//     Node* fast = floydCycleDetection(head);
//     Node* slow = head;

//     while(slow!=fast){
//         slow = slow->next;
//         fast = fast->next;
//     };
//         return fast;
// }

// void removeCycle(Node* head) {
//     if(head == NULL || floydCycleDetection(head) == NULL) return ;
//     Node* start = getStartingPoint(head);
//     Node* temp = start;
    

//     while(temp->next != start){
//         temp = temp->next;
        
//     };

//     temp->next = NULL;
//     // print(head);
// }

Node* reverseLL(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* temp = head;
    Node* prev = NULL;
    Node* forward;
    while(temp!= NULL){
        forward = temp->next;
        temp->next = prev;
        prev = temp;
        temp = forward;
    }
    return prev;
};

Node* rotate(Node* head, int k){

    int c = 0 ;
    Node* temp = head;
    while(temp != NULL){
        temp = temp->next;
        c++;
    };
    cout<<"size is "<< c <<endl;

    k = k%c;

    // int r = (c-k);
    int r = 0;
    temp = head;
    while(temp != NULL &&  r < (c-k)){
        temp = temp->next;
        r++;
    };

    Node* forwardHead = temp->next;
    Node* forwardTail = forwardHead;
    temp->next = NULL;
    while(forwardTail->next!=NULL){
        forwardTail = forwardTail->next;
    }

    forwardTail->next = head;

    return forwardHead;
}

Node* rotateLL(Node* head, int k) {
    if (head == nullptr || k <= 0) {

        return head;
    }

    int size = 1;
    Node* temp = head;


    while (temp->next != nullptr) {
        temp = temp->next;
        size++;
    }

    k = k % size;


    if (k == 0) {
        return head;
    }

    temp = head;
    int rotatePoint = size - k - 1;


    while (rotatePoint > 0) {
        temp = temp->next;
        rotatePoint--;
    }

    Node* forwardHead = temp->next;
    temp->next = nullptr;
    temp = forwardHead;


    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = head;

    return forwardHead;
}



int main(){

    Node * n1 = new Node(10);
    // cout<<n1->next<<endl;
    insertAtHead(n1 , 20);
    insertAtHead(n1 , 30);
    insertAtHead(n1 , 40);
    insertAtHead(n1 , 50);
    insertAtHead(n1 , 60);
    insertAtHead(n1 , 70);
    print(n1);
    Node * n2 = rotate(n1 , 1);
    print(n2);
    Node * n3 = rotate(n2 , 2);
    print(n3);
    // Node * n4 = rotate(n1 , 6);
    // print(n4);

    return 0;
}
