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

TreeNode* insertIntoBST(TreeNode* root, int val) {
    TreeNode* temp = root;
    TreeNode* pre = nullptr;

    while (temp != nullptr) {
        if (temp->val > val) {
            pre = temp;
            temp = temp->left;
        } else if (temp->val < val) {
            pre = temp;
            temp = temp->right;
        }
    }

    if (pre != nullptr) {
        if (pre->val > val) {
            pre->left = new TreeNode(val);
        } else {
            pre->right = new TreeNode(val);
        }
    } else {
        root = new TreeNode(val);
    }

    return root;
}

int main() {
    TreeNode* root = new TreeNode(0);
    // root->right = new TreeNode(2);
    // root->right->left = new TreeNode(2);
    // root->left->right = new TreeNode(44);
    // root->left->right->left = new TreeNode(43);
    // root->left->right->left->left = new TreeNode(41);

    // auto result = findMode(root);
}