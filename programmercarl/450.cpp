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

TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == nullptr) return root;

    TreeNode* cur = root;
    TreeNode* pre = nullptr;

    while (cur != nullptr) {
        if (cur->val > key) {
            pre = cur;
            cur = cur->left;
        } else if (cur->val < key) {
            pre = cur;
            cur = cur->right;
        } else if (cur->val == key) {
            break;
        }
    }

    if (cur == nullptr) return root;

    if (pre == nullptr) {
        if (cur->left != nullptr && cur->right == nullptr) {
            root = cur->left;
        } else if (cur->left == nullptr && cur->right != nullptr) {
            root = cur->right;
        } else if (cur->left != nullptr && cur->right != nullptr) {
            TreeNode* temp = cur->left;
            while (temp->right != nullptr) {
                temp = temp->right;
            }
            temp->right = cur->right;
            root = cur->left;
        } else {
            root = nullptr;
        }
    } else {
        if (cur->left != nullptr && cur->right == nullptr) {
            if (pre->left == cur) {
                pre->left = cur->left;
            } else {
                pre->right = cur->left;
            }
        } else if (cur->left == nullptr && cur->right != nullptr) {
            if (pre->left == cur) {
                pre->left = cur->right;
            } else {
                pre->right = cur->right;
            }
        } else if (cur->left != nullptr && cur->right != nullptr) {
            TreeNode* temp = cur->left;
            while (temp->right != nullptr) {
                temp = temp->right;
            }
            temp->right = cur->right;

            if (pre->left == cur) {
                pre->left = cur->left;
            } else {
                pre->right = cur->left;
            }
        } else {
            if (pre->left == cur) {
                pre->left = nullptr;
            } else {
                pre->right = nullptr;
            }
        }
    }
    delete cur;

    return root;
}

int main() {
    TreeNode* root = new TreeNode(0);
    // root->right = new TreeNode(2);
    // root->right->left = new TreeNode(2);
    // root->left->right = new TreeNode(44);
    // root->left->right->left = new TreeNode(43);
    // root->left->right->left->left = new TreeNode(41);

    auto result = deleteNode(root, 0);
}