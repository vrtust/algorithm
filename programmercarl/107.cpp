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

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
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
                temp.push_back(node->left->val);
            }
            if (node->right != nullptr) {
                queue_treenode.push(node->right);
                temp.push_back(node->right->val);
            }

        }
        if (temp.size() > 0) {
            result.push_back(temp);
        }
    }

    return result;
}

vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> temp = levelOrder(root);

    vector<vector<int>> result;
    while (!temp.empty()) {
        result.push_back(temp.back());
        temp.pop_back();
    }

    return result;
}

int main() {
    TreeNode* root = new TreeNode();

    levelOrderBottom(root);
}