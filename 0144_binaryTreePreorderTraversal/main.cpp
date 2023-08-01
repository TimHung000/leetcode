#include <vector>
#include <stack>

// Definition for a binary tree node.
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
    std::vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> res;
        std::stack<TreeNode*> st;

        while (root || !st.empty()) {
            while (root) {
                res.push_back(root -> val);
                st.push(root);
                root = root -> left;
            }
            root = st.top();
            st.pop();
            root = root -> right;
        }
        return res;
    }
};

class Solution1 {
public:
    std::vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> res;
        inorder(root, res);
        return res;
    }
private:
    void inorder(TreeNode* root, std::vector<int>& res) {
        if (!root) {
            return;
        }
        res.push_back(root -> val);
        inorder(root -> left, res);
        inorder(root -> right, res);
    }
};

class Solution2 {
public:
    std::vector<int> preorderTraversal(TreeNode* root) {
        if(!root)
            return {};

        std::vector<int> res;
        std::stack<TreeNode*> st;
        st.push(root);
        TreeNode *cur;

        while (!st.empty()) {
            cur = st.top();
            st.pop();
            res.push_back(cur->val);
            if(cur->right)
                st.push(cur->right);
            if(cur->left)
                st.push(cur->left);
        }
        return res;
    }
};