#include <bits/stdc++.h>
using namespace std;



// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
    public:
        Node* cloneGraph(Node* node) {
            if(!node) return nullptr;

            Node* newNode = new Node(node->val);
            unordered_map<Node* , Node*> map;
            queue<Node*> q;
            q.push(node);
            map[node] = newNode;

            while(!q.empty()){
                Node* parent = q.front() ; q.pop();

                for(Node* adj : parent->neighbors){
                    if(map.find(adj) == map.end()) {
                    map[adj] = new Node(adj->val);
                    q.push(adj);
                }

                    map[parent]->neighbors.push_back(map[adj]);

                }
            }

            return newNode;
        }
    };
int main(){

    return 0;
}