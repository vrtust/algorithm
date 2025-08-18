#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

void preorder(TreeNode* root, vector<int>& result) {
    if (root == nullptr) return;

    result.push_back(root->val);
    preorder(root->left, result);
    preorder(root->right, result);
}

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> result;
    preorder(root, result);
    return result;
}


int main() {
    TreeNode* treeNode = new TreeNode(1);
    treeNode->right = new TreeNode(2);
    treeNode->right->left = new TreeNode(3);

    preorderTraversal(treeNode);
}