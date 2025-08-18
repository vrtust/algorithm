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

bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == nullptr && q == nullptr) {
        return true;
    } else if (p == nullptr || q == nullptr) {
        return false;
    }
    if (p->val != q->val) return false;
    if (isSameTree(p->left, q->left) && isSameTree(p->right, q->right)) {
        return true;
    } else {
        return false;
    }
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
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

            if (node->val == subRoot->val && isSameTree(node, subRoot)) {
                return true;
            }

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
    return false;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);

    TreeNode* subRoot = new TreeNode(4);
    subRoot->left = new TreeNode(1);
    subRoot->right = new TreeNode(2);

    bool result = isSameTree(root, subRoot);
}