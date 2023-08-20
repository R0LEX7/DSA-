#include <bits/stdc++.h>
#include<unordered_map>
#include <queue>
//   Definition for a binary tree node.
  struct TreeNode {
      int val;
    TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
private:
    void markParents(TreeNode* root, unordered_map<TreeNode*,TreeNode*>& 
    parent_track,TreeNode* target){
           queue<TreeNode*> q;
           q.push(root);

           while(!q.empty()){
               TreeNode* node = q.front();
               q.pop();

               if(node->left){
                   parent_track[node->left] = node;
                   q.push(node->left);
               }
               if(node->right){
                   parent_track[node->right] = node;
                   q.push(node->right);
               }
           }

    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> result;
        if(!root) return result;

        unordered_map<TreeNode*,TreeNode*> parent_track;
        markParents(root,parent_track , target);
        unordered_map<TreeNode* , bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int curr_level = 0;

        while(!q.empty()){
            int n = q.size();
            if(curr_level++ == k ) break;
            for(int i=0 ; i<n ; i++){
                TreeNode* node = q.front();
                q.pop();

                if(node->left && !visited[node->left]){
                   visited[node->left] = true;
                   q.push(node->left);
               }
               if(node->right && !visited[node->right]){
                   visited[node->right] = true;
                   q.push(node->right);
               }
               if(parent_track[node] && !visited[parent_track[node]]){
                   visited[parent_track[node]] = true;
                   q.push(parent_track[node]);
               }
               
            }
        }
        while(!q.empty()){
            result.push_back(q.front()->val);
            q.pop();
        }
        return result;
    }
};