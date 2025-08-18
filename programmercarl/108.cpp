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

TreeNode* build(vector<int>& nums, int start, int end) {
    if (start > end) return nullptr;

    int mid = (end - start) / 2 + start;

    TreeNode* root = new TreeNode(nums[mid]);
    root->left = build(nums, start, mid - 1);
    root->right = build(nums, mid + 1, end);

    return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    if (nums.empty()) return nullptr;

    TreeNode* root = nullptr;
    return build(nums, 0, nums.size() - 1);
}

int main() {
    TreeNode* root = new TreeNode(0);
    // root->right = new TreeNode(2);
    // root->right->left = new TreeNode(2);
    // root->left->right = new TreeNode(44);
    // root->left->right->left = new TreeNode(43);
    // root->left->right->left->left = new TreeNode(41);

    // auto result = deleteNode(root, 0);
}