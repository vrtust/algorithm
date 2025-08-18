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

void invert(TreeNode* root) {
    if (root == nullptr) return;

    TreeNode* node = root->left;
    root->left = root->right;
    root->right = node;
    invert(root->left);
    invert(root->right);
}

TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) return root;
    invert(root);
    return root;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    invertTree(root);
}