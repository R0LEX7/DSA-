#include<iostream>
#include<map>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void print(Node* tail){
    // if list is empty
    if(tail == NULL){
        cout <<"Empty list" << endl;
        
    }else {


    Node* cur = tail;
    do
    {
        cout<<cur->data<<" ";
        cur = cur->next;
    } while (cur != tail);
    }
    cout << endl;
}

void insert(Node* &tail, int element, int d) {
    

    //empty list
    if(tail == NULL) {
        Node* newNode = new Node(d);
        tail = newNode;
        newNode -> next = newNode;
    }
    else{
        //non-empty list
        //assuming that the element is present in the list

        Node* curr = tail;

        while(curr->data != element) {
            curr = curr -> next;
        }
        
        //element found -> curr is representing element wala node
        Node* temp = new Node(d);
        temp -> next = curr -> next;
        curr -> next = temp;

    }

}    


bool detectCycle(Node* head){
    if(head == NULL) return false;
    Node* curr = head;
    map<Node* , bool> visited;

    while(curr!=NULL){
        if(visited[curr] == true){
            return true;
        };
        visited[curr] = true;
        curr = curr->next;
    }
    return false;
}

bool floydCycleDetection(Node * head){
    if(head == NULL) return false;
    Node * slow = head;
    Node * fast = head;

    while(fast->next != NULL){
        fast = fast->next;
        if(fast->next != NULL){
            fast = fast->next;
        };
        slow = slow->next;
        if(slow == fast){
            return true;
        }
    }

    return false;
}




int main(){
    cout<<"Welcome "<<endl;
    Node* tail = new Node(10);
    insert(tail , 10 , 30);
    cout<<"tail -> "<<tail->data<<endl;
    print(tail);
    // insert(tail , 20 , 30);
    // cout<<tail->next->next->data<<endl;
    // print(tail);
    // insert(tail , 30 , 50);
    // print(tail);
    // insert(tail , 30 , 40);
    // print(tail);
    // std::cout.flush();
    if(detectCycle(tail)){
        cout<<"cycle detected"<<endl;
    }else{
        cout<<"cycle not present"<<endl;
    }
    return 0;
}