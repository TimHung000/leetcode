#include <vector>
#include <unordered_map>
#include <string>

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
private:
    std::string serializeSubtrees(TreeNode* node, std::unordered_map<std::string, int>& subtree, std::vector<TreeNode*>& res) {
        if(!node)
            return "null";

        std::string left = serializeSubtrees(node->left, subtree, res);
        std::string right = serializeSubtrees(node->right, subtree, res);
        std::string s = std::to_string(node->val) + "," + left + "," + right;

        if(subtree[s] == 1)
            res.push_back(node);
        ++subtree[s];
        return s;
    }
public:
    std::vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        std::unordered_map<std::string, int> subtree;
        std::vector<TreeNode*> res;
        serializeSubtrees(root, subtree, res);
        return res;
    }
};