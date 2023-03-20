#include <stack>
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
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root)
        {
            invertTree(root->left);
            invertTree(root->right);
            TreeNode* tmp = root->left;
            root->left = root->right;
            root->right = tmp;
        }
        return root;
    }
    TreeNode* invertTree1(TreeNode* root) {

        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty())
        {
            TreeNode* ptr = st.top();
            st.pop();
            if(ptr)
            {
                st.push(ptr->left);
                st.push(ptr->right);
                TreeNode* tmp = root->left;
                root->left = root->right;
                root->right = tmp;                
            }
        }
    }
};