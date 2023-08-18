#include <queue>
#include <vector>
#include <utility>

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
    // BFS Implementation
    vector<vector<int>> levelOrder(TreeNode* root) {

        if(!root)
            return std::vector<vector<int>>();

        std::vector<std::vector<int>> res;

        std::queue<struct TreeNode*> myQueue;
        myQueue.push(root);

        struct TreeNode *curPtr = nullptr;
        int levelLength = 0;

        while(!myQueue.empty()) {
            levelLength = myQueue.size();
            res.push_back(std::vector<int>());
            for(int i = 0; i < levelLength; ++i) {
                curPtr = myQueue.front();
                myQueue.pop();
                res.back().push_back(curPtr->val);
                if(curPtr->left)
                    myQueue.push(curPtr->left);
                if(curPtr->right)
                    myQueue.push(curPtr->right);
            }
        }
        return res;
    }
};
