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
    std::vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> res;
        inorder(root, res);
        return res;
    }
private:
    void inorder(TreeNode* root, std::vector<int>& res) {
        if (!root) {
            return;
        }
        inorder(root -> left, res);
        inorder(root -> right, res);
        res.push_back(root -> val);
    }
};

class Solution1 {
public:
    std::vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> res;
        std::stack<TreeNode*> st;
        TreeNode* last = NULL;
        while (root || !st.empty()) {
            if (root) {
                st.push(root);
                root = root -> left;
            } else {
                TreeNode* node = st.top();
                if (node -> right && last != node -> right) {
                    root = node -> right;
                } else {
                    res.push_back(node -> val);
                    last = node;
                    st.pop();
                }
            }
        }
        return res;
    }
};


class Solution2 {
public:
    std::vector<int> postorderTraversal(TreeNode* root) {
        if(!root)
            return {};

        std::stack<TreeNode*> s1;
        std::stack<TreeNode*> s2;
        std::vector<int> res;
        s1.push(root);
        while(!s1.empty()){
            root=s1.top();
            s1.pop();

            if(root->left)
                s1.push(root->left);
            
            if(root->right!=NULL)
                s1.push(root->right);
            
            s2.push(root);
        }
        while(!s2.empty()){
            res.push_back(s2.top()->val);
            s2.pop();
        }
        return res;
    }
};