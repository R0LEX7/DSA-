#include <bits/stdc++.h>
using namespace std;


  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
    unordered_map<int, int> map;
    public:
        TreeNode* build(vector<int> &pre, vector<int> &post ,int preStart , int preEnd ,int postStart ,int postEnd ){

            if(preStart > preEnd) return nullptr;

            TreeNode* root = new TreeNode(pre[preStart]);
            if(preStart == preEnd) return root;

            int leftRootInd = map[pre[preStart+1]];

            int lenOfLeftSubTree = leftRootInd - postStart +1;

            root->left = build(pre , post , preStart+1 , preStart + lenOfLeftSubTree , postStart , leftRootInd);

            root->right = build(pre , post , preStart + leftRootInd +1 , preEnd , leftRootInd +1,postEnd -1);

            return root;

        };


        TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
            int n = postorder.size();
            if(n==0) return nullptr;
           for(int i = 0 ; i < n ; i++)  map[postorder[i]] = i;

           return build( preorder,  postorder , 0 , n-1 , 0 , n-1 );

        }
    };


int main(){



    return 0;
}