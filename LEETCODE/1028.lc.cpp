#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *recoverFromPreorder(string traversal)
    {
        int n = traversal.size();
        stack<TreeNode *> st;

        TreeNode *root = new TreeNode(traversal[0] - '0');
        st.push(root);
        int i = 1;

        while (i < n)
        {
            int depth = 0;

            while (i < n && traversal[i] == '-')
            {
                i++;
                depth++;
            }

            int num = 0;
            while (i < n && isdigit(traversal[i]))
            {
                num = num * 10 + (traversal[i] - '0');
                i++;
            }

            TreeNode *newNode = new TreeNode(num);

            while (st.size() > depth)
                st.pop();

            if (!st.empty())
            {
                TreeNode *node = st.top();

                if (node->left == nullptr)
                    node->left = newNode;
                else
                    node->right = newNode;
            }
            st.push(newNode);
        }

        return root;
    }
};

int main()
{

    return 0;
}
