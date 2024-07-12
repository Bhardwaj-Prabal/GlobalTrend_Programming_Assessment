#include <iostream>
#include <sstream>
#include <string>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        serializeHelper(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserializeHelper(in);
    }

private:
    void serializeHelper(TreeNode* root, ostringstream &out) {
        if (root == NULL) {
            out << "# ";
            return;
        }
        out << root->val << " ";
        serializeHelper(root->left, out);
        serializeHelper(root->right, out);
    }

    TreeNode* deserializeHelper(istringstream &in) {
        string val;
        in >> val;
        if (val == "#") {
            return NULL;
        }
        TreeNode* node = new TreeNode(stoi(val));
        node->left = deserializeHelper(in);
        node->right = deserializeHelper(in);
        return node;
    }
};

void printTree(TreeNode* root) {
    if (root == NULL) {
        cout << "# ";
        return;
    }
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Codec codec;
    string serializedTree = codec.serialize(root);
    cout << "Serialized Tree: " << serializedTree << endl;

    TreeNode* deserializedRoot = codec.deserialize(serializedTree);
    cout << "Deserialized Tree: ";
    printTree(deserializedRoot);
    cout << endl;

    return 0;
}
