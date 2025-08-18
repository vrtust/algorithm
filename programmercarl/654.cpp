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

TreeNode* traversal(vector<int>& nums, int begin, int end) {
    if (begin > end) {
        return nullptr;
    }

    int max_num = -1;
    int index;
    for (int i = begin; i <= end; i++) {
        if (nums[i] > max_num) {
            max_num = nums[i];
            index = i;
        }
    }

    TreeNode* root = new TreeNode(max_num);

    int left_begin = begin;
    int left_end = index - 1;
    int right_begin = index + 1;
    int right_end = end;

    root->left = traversal(nums, left_begin, left_end);
    root->right = traversal(nums, right_begin, right_end);
    return root;
}

TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    if (nums.empty()) return nullptr;
    return traversal(nums, 0, nums.size() - 1);
}

int main() {
    vector<int> nums = { 3,2,1,6,0,5 };

    constructMaximumBinaryTree(nums);
}