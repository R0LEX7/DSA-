#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
    public:
        Node* copyRandomList(Node* head) {
            unordered_map<Node*, Node*> map;
            Node* temp = head;

            while(temp){
                Node* newNode = new Node(temp->val);
                map[temp] = newNode;
                temp = temp->next;
            };

            temp = head;
            Node* newHead = new Node(0);

            while(temp){
                Node* newNode = map[temp];
                newNode->next = map[temp->next];
                newNode->random = map[temp->random];
                temp = temp->next;
            };
            return newHead->next;
        }
    };

int main(){

    return 0;
}