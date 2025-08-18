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

void traversal(TreeNode* root, vector<int>& all_result) {
    if (root->left == nullptr && root->right == nullptr) {
        return;
    }

    if (root->left != nullptr) {
        if (root->left->left == nullptr && root->left->right == nullptr) {
            all_result.push_back(root->left->val);
        }
        traversal(root->left, all_result);
    }
    if (root->right != nullptr) {
        traversal(root->right, all_result);
    }
}

int sumOfLeftLeaves(TreeNode* root) {
    int result = 0;
    vector<int> all_result;
    traversal(root, all_result);

    for (auto num : all_result) {
        result += num;
    }

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

    sumOfLeftLeaves(root);
}