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
int result;

void traversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    traversal(root->left);
    if (pre != nullptr) {
        result = min(result, abs(root->val - pre->val));
    }
    pre = root;
    traversal(root->right);
}

int getMinimumDifference(TreeNode* root) {
    result = 100000;
    traversal(root);

    return result;
}

int main() {
    TreeNode* root = new TreeNode(45);
    root->left = new TreeNode(42);
    root->left->right = new TreeNode(44);
    root->left->right->left = new TreeNode(43);
    root->left->right->left->left = new TreeNode(41);

    // isValidBST(root);
}