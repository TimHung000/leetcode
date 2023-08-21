#include <vector>
#include <queue>

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
    std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)
            return std::vector<std::vector<int>>();
        std::queue<TreeNode*> myqueue;
        std::vector<std::vector<int>> res;

        myqueue.push(root);
        int levelLength = 0;
        TreeNode *curNode;
        while(!myqueue.empty()) {
            std::vector<int> level;
            levelLength = myqueue.size();

            for(int i = 0; i < levelLength; ++i) {
                curNode = myqueue.front();
                myqueue.pop();
                level.push_back(curNode->val);
                if(curNode->left)
                    myqueue.push(curNode->left);
                if(curNode->right)
                    myqueue.push(curNode->right);
            }

            if(res.size() % 2 == 1)
                std::reverse(level.begin(), level.end());
            res.push_back(level);
        }
        return res;
    }
};
