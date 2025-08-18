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

int maxDepth(TreeNode* root) {
    deque<TreeNode*> dq;

    if (root != nullptr) {
        dq.push_back(root);
    }

    int count = 0;

    while (!dq.empty()) {
        int size = dq.size();
        for (int i = 0; i < size; i++) {
            count++;
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

    return count;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    bool result = maxDepth(root);
}