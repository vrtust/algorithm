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

void traversal(TreeNode* root, vector<vector<int>>& all_path, vector<int>& path, int target) {
    if (root->left == nullptr && root->right == nullptr && target - root->val == 0) {
        all_path.push_back(path);
    }

    if (root->left != nullptr) {
        path.push_back(root->left->val);
        traversal(root->left, all_path, path, target - root->val);
        path.pop_back();
    }

    if (root->right != nullptr) {
        path.push_back(root->right->val);
        traversal(root->right, all_path, path, target - root->val);
        path.pop_back();
    }
}

vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    if (root == nullptr) return {};
    vector<vector<int>> all_path;
    vector<int> path;
    path.push_back(root->val);
    vector<vector<int>> result;

    traversal(root, all_path, path, targetSum);

    return all_path;
}

int main() {
    TreeNode* root = new TreeNode(1);
    // root->left = new TreeNode(2);
    // root->right = new TreeNode(3);
    // root->left->left = new TreeNode(4);
    // root->right->left = new TreeNode(5);
    // root->right->right = new TreeNode(6);
    // root->right->left->left = new TreeNode(7);

    pathSum(root, 1);
}