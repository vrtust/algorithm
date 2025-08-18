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

vector<int> largestValues(TreeNode* root) {
    vector<int> result;
    queue<TreeNode*> queue_treenode;

    if (root != nullptr) {
        queue_treenode.push(root);
        result.push_back({ root->val });
    }

    while (!queue_treenode.empty()) {
        int size = queue_treenode.size();
        vector<int> temp;
        for (int i = 0; i < size; i++) {
            TreeNode* node = queue_treenode.front();
            queue_treenode.pop();
            if (node->left != nullptr) {
                queue_treenode.push(node->left);
                if (temp.empty()) {
                    temp.push_back(node->left->val);
                } else if (node->left->val > temp.back()) {
                    temp.pop_back();
                    temp.push_back(node->left->val);
                }
            }
            if (node->right != nullptr) {
                queue_treenode.push(node->right);
                if (temp.empty()) {
                    temp.push_back(node->right->val);
                } else if (node->right->val > temp.back()) {
                    temp.pop_back();
                    temp.push_back(node->right->val);
                }
            }

        }
        if (!temp.empty()) {
            result.push_back(temp.back());
        }
    }

    return result;
}


int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(9);

    largestValues(root);
}