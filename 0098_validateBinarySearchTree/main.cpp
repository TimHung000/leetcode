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

// using iterative inorder traversal
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        
        if(!root)
            return true;
        
        stack<TreeNode*> st;
        TreeNode* previous = nullptr;
        while(root || !st.empty())
        {
            while(root)
            {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            if(previous && root-> val <= previous->val)
                return false;

            previous = root;
            root = root->right;
        }
        return true;
    }
};

// using recursive inorder traversal
class Solution1 {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = nullptr;
        return validate(root, prev);
    }
    bool validate(TreeNode* root, TreeNode* &prev) {
        if (root == nullptr) return true;
        if (!validate(root->left, prev)) return false;
        if (prev != nullptr && prev->val >= root->val) return false;
        prev = root;
        return validate(root->right, prev);
    }
};

// recursive with min and max node
class Solution2 {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, nullptr, nullptr);
    }

    bool isValidBST(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
        if(!root) return true;
        if(minNode && root->val <= minNode->val || maxNode && root->val >= maxNode->val)
            return false;
        return isValidBST(root->left, minNode, root) && isValidBST(root->right, root, maxNode);
}
};