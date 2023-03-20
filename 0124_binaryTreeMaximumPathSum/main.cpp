#include <stack>
#include <limits>
#include <algorithm>

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
private:
    int maxPath;

    int buildMax(TreeNode* root)
    {
        if(!root) return 0;
        int leftMaxPathToRoot = max(0, buildMax(root->left));
        int rightMaxPathToRoot = max(0, buildMax(root->right));
        maxPath = max(maxPath, root->val + leftMaxPathToRoot + rightMaxPathToRoot);
        return root->val + max(leftMaxPathToRoot, rightMaxPathToRoot);  
    }
public:
    int maxPathSum(TreeNode* root) {
        maxPath = numeric_limits<int>::min();
        buildMax(root);
        return maxPath;
    }
};
