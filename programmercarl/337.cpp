#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
#include<math.h>
#include<unordered_set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

vector<int> robUtil(TreeNode* root) {
    if (root == nullptr) return { 0,0 };

    vector<int> left = robUtil(root->left);
    vector<int> right = robUtil(root->right);

    int val1 = root->val + left[1] + right[1];
    int val2 = max(left[0], left[1]) + max(right[0], right[1]);

    return { val1, val2 };
}

int rob(TreeNode* root) {
    if (root == nullptr) return 0;

    vector<int> result = robUtil(root);

    return max(result[0], result[1]);
}

int main() {
    // vector<int> nums = { 1,2,3,1 };
    // auto result = rob(nums);

    return 0;
}