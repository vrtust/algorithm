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

struct result {
    bool is_bst;
    int max;
    bool left_max;
    int min;
    bool right_min;
};

result traversal(TreeNode* root) {
    if (root == nullptr) {
        return { true, 0, false, 0, false };
    }

    if ((root->left != nullptr && root->left->val >= root->val) || (root->right != nullptr && root->right->val <= root->val)) {
        return { false, 0, false, 0, false };
    } else {
        result left = traversal(root->left);
        result right = traversal(root->right);

        if (!left.is_bst || !right.is_bst) {
            return { false, 0, false, 0, false };
        } else if (left.left_max && left.max >= root->val) {
            return { false, 0, false, 0, false };
        } else if (right.right_min && right.min <= root->val) {
            return { false, 0, false, 0, false };
        }

        int tmp_max = root->val;
        if (right.left_max && left.left_max) {
            tmp_max = max(tmp_max, right.max);
            tmp_max = max(tmp_max, left.max);
        } else if (!right.left_max && left.left_max) {
            tmp_max = max(tmp_max, left.max);
        } else if (right.left_max && !left.left_max) {
            tmp_max = max(tmp_max, right.max);
        }

        int tmp_min = root->val;
        if (right.right_min && left.right_min) {
            tmp_min = min(tmp_min, right.min);
            tmp_min = min(tmp_min, left.min);
        } else if (!right.right_min && left.right_min) {
            tmp_min = min(tmp_min, left.min);
        } else if (right.right_min && !left.right_min) {
            tmp_min = min(tmp_min, right.min);
        }

        return { true, tmp_max, true, tmp_min, true };
    }
}

bool isValidBST(TreeNode* root) {
    return traversal(root).is_bst;
}

int main() {
    TreeNode* root = new TreeNode(45);
    root->left = new TreeNode(42);
    root->left->right = new TreeNode(44);
    root->left->right->left = new TreeNode(43);
    root->left->right->left->left = new TreeNode(41);

    isValidBST(root);
}