#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

TreeNode* pre = nullptr;
int old_count = 0;
int new_count = 0;

void traversal(TreeNode* root, vector<int>& result) {
    if (root == nullptr) {
        return;
    }

    traversal(root->left, result);

    if (pre == nullptr) {
        new_count = 1;
    } else if (pre->val == root->val) {
        new_count++;
    } else {
        new_count = 1;
    }

    pre = root;

    if (new_count == old_count) {
        result.push_back(pre->val);
    }

    if (new_count > old_count) {
        old_count = new_count;
        result.clear();
        result.push_back(pre->val);
    }

    traversal(root->right, result);
}

vector<int> findMode(TreeNode* root) {
    vector<int> result;
    traversal(root, result);
    return result;
}

int main() {
    TreeNode* root = new TreeNode(0);
    // root->right = new TreeNode(2);
    // root->right->left = new TreeNode(2);
    // root->left->right = new TreeNode(44);
    // root->left->right->left = new TreeNode(43);
    // root->left->right->left->left = new TreeNode(41);

    auto result = findMode(root);
}