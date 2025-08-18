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

int main() {
    TreeNode* p = new TreeNode(10);
    p->left = new TreeNode(5);
    p->right = new TreeNode(15);

    TreeNode* q = new TreeNode(10);
    q->left = new TreeNode(5);
    q->left->right = new TreeNode(15);

    bool result = isSameTree(p, q);
}