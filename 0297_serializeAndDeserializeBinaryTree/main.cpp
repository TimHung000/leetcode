#include <string>
#include <sstream>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    string serialize(TreeNode* root)
    {
        ostringstream out;
        serialize(root, out);
        return out.str();
    }

    TreeNode* deserialize(string data)
    {
        istringstream in(data);
        return deserialize(in);
    }

private:
    void serialize(TreeNode* root, ostringstream& out)
    {
        if(root)
        {
            out << root->val << ' ';
            serialize(root->left, out);
            serialize(root->right, out);
        }
        else
        {
            out << "# ";
        }
    }

    TreeNode* deserialize(istringstream& in)
    {
        string str;
        in >> str;
        if(str == "#")
            return nullptr;
        TreeNode* root = new TreeNode(stoi(str));
        root->left = deserialize(in);
        root->right = deserialize(in);
        return root;
    }
    
};

class Codec1 {
public:

    // Encodes a tree to a single string.
    string serialize1(TreeNode* root) {
        if(!root)
            return "#";
        return to_string(root->val) + "," + serialize1(root->left) + "," + serialize1(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize1(string data) {
        stringstream ss(data);
        return makeDeserialize1(ss);
    }

private:

    TreeNode* makeDeserialize1(stringstream& ss)
    {
        string str;
        getline(ss, str, ',');
        if(str == "#")
            return nullptr;
        else
        {
            TreeNode* root = new TreeNode(stoi(str));
            root->left = makeDeserialize1(ss);
            root->right = makeDeserialize1(ss);
            return root;
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));