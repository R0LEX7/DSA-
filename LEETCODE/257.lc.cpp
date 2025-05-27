#include <bits/stdc++.h>
using namespace std;


int main(){

    return 0;
}

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
    public:
        void help(TreeNode* root , vector<string> &ans , string &current){
            if(!root){
                current.pop_back();
                ans.push_back(current);
                return;
            };

            current += to_string(root->val);
            current.push_back('->');
            if ( root->left!= nullptr )help(root->left, ans, current);
            else help(root->right, ans, current);

        }
        vector<string> binaryTreePaths(TreeNode* root) {
            vector<string> ans;
            string current = "";
            help(root, ans, current);
            return ans;
        }
    };
