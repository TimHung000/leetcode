#include <stack>
#include <cstddef>

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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;

        while(root || !st.empty())
        {
            while(root)
            {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            if(--k == 0) break;
            root = root->right;
        }
        return root->val;
    }
};

class Solution1 {
public:
    int kthSmallest(TreeNode* root, int k) {
        return find(root, k);
    }
    int find(TreeNode* root, int& k) {
        int res = (int)NULL;
        if (root) {
            int x = find(root->left, k);
            if(k == 0)
                res = x;
            else
            {
                if(--k == 0)
                    res = root->val;
                else
                    res = find(root->right, k);
            }
        }
        return res;
    }
};