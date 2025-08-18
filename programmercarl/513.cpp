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

int findBottomLeftValue(TreeNode* root) {
    int result = 0;
    deque<TreeNode*> dq;

    if (root != nullptr) {
        dq.push_back(root);
    }

    while (!dq.empty()) {
        int size = dq.size();
        if (dq.front() != nullptr) {
            result = dq.front()->val;
        }
        for (int i = 0; i < size; i++) {
            TreeNode* node = dq.front();
            dq.pop_front();
            if (node->left != nullptr) {
                dq.push_back(node->left);
            }
            if (node->right != nullptr) {
                dq.push_back(node->right);
            }
        }
    }

    return result;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->right->left->left = new TreeNode(7);

    findBottomLeftValue(root);
}