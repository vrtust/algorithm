#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

void traversal(TreeNode* root, string path, vector<string>& result) {
    path += to_string(root->val);

    if (root->left == nullptr && root->right == nullptr) {
        result.push_back(path);
        return;
    }

    if (root->left != nullptr) {
        traversal(root->left, path + "->", result);
    }
    if (root->right != nullptr) {
        traversal(root->right, path + "->", result);
    }
}

vector<string> binaryTreePaths(TreeNode* root) {
    string path = "";
    vector<string> result;
    traversal(root, path, result);
    return result;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    // root->right->right = new TreeNode(3);
    // root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(5);
    // root->right->left->left = new TreeNode(4);
    // root->right->left->right = new TreeNode(4);

    binaryTreePaths(root);
}