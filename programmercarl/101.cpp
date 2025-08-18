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

bool isSymmetric(TreeNode* root) {
    vector<vector<int>> result;
    queue<TreeNode*> queue_treenode;

    if (root != nullptr) {
        queue_treenode.push(root);
        result.push_back({ root->val });
    }

    while (!queue_treenode.empty()) {
        int size = queue_treenode.size();
        deque<int> temp;
        for (int i = 0; i < size; i++) {
            TreeNode* node = queue_treenode.front();
            queue_treenode.pop();
            if (node->left != nullptr) {
                queue_treenode.push(node->left);
                temp.push_back(node->left->val);
            } else {
                temp.push_back(-999);
            }
            if (node->right != nullptr) {
                queue_treenode.push(node->right);
                temp.push_back(node->right->val);
            } else {
                temp.push_back(-999);
            }

        }
        if (temp.size() % 2 == 0) {
            while (!temp.empty()) {
                if (temp.front() != temp.back()) {
                    return false;
                }
                temp.pop_front();
                temp.pop_back();
            }
        } else {
            return false;
        }
    }

    return true;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(3);

    isSymmetric(root);
}