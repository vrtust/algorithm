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

int getHeight(TreeNode* root){
    if(root==nullptr){
        return 0;
    }
    int left_height = getHeight(root->left);
    if (left_height == -1) return -1;
    int right_height = getHeight(root->right);
    if (right_height == -1) return -1;
    return abs(left_height-right_height) > 1 ? -1 : max(left_height, right_height) + 1;
}

bool isBalanced(TreeNode* root) {
    // deque<TreeNode*> dq;

    // if (root != nullptr) {
    //     dq.push_back(root);
    // }

    // int max = 0;
    // int min = 0;
    // bool find_min = false;

    // while (!dq.empty()) {
    //     max++;
    //     if (!find_min) {
    //         min++;
    //     }
    //     int size = dq.size();
    //     for (int i = 0; i < size; i++) {
    //         TreeNode* node = dq.front();
    //         dq.pop_front();
    //         if (node->left != nullptr) {
    //             dq.push_back(node->left);
    //             if (!find_min && (node->left->left == nullptr || node->left->right == nullptr)) {
    //                 min++;
    //                 find_min = true;
    //             }
    //         } else if (!find_min) {
    //             find_min = true;
    //         }
    //         if (node->right != nullptr) {
    //             dq.push_back(node->right);
    //             if (!find_min && (node->right->left == nullptr || node->right->right == nullptr)) {
    //                 min++;
    //                 find_min = true;
    //             }
    //         } else if (!find_min) {
    //             find_min = true;
    //         }
    //     }
    // }

    // return max - min > 1 ? false : true;

    return getHeight(root) == -1 ? false : true;
}

int main() {
    TreeNode* root = new TreeNode(1);
    // root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    // root->left->left = new TreeNode(3);
    // root->left->right = new TreeNode(3);
    // root->right->left->left = new TreeNode(4);
    // root->right->left->right = new TreeNode(4);

    bool result = isBalanced(root);
}