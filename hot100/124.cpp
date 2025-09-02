#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<stack>
#include<unordered_set>
#include<queue>
#include<stack>
#include<set>

using namespace std;

#define null -1000

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

TreeNode* build(vector<int> nums) {
    if (nums.empty()) return nullptr;

    TreeNode* root = new TreeNode(nums[0]);
    queue<TreeNode*> que;
    que.push(root);

    int i = 1;
    int n = nums.size();
    while (!que.empty() && i < n) {
        TreeNode* cur = que.front();
        que.pop();

        if (i < n && nums[i] != -1000) {
            cur->left = new TreeNode(nums[i]);
            que.push(cur->left);
        }
        i++;

        if (i < n && nums[i] != -1000) {
            cur->right = new TreeNode(nums[i]);
            que.push(cur->right);
        }
        i++;
    }

    return root;
}

int maxSum = -1001;

int dfs(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    int left = max(dfs(root->left), 0);
    int right = max(dfs(root->right), 0);

    maxSum = max(maxSum, root->val + left + right);

    return root->val + max(left, right);
}

int maxPathSum(TreeNode* root) {
    auto result = dfs(root);

    return maxSum;
}

int main() {
    TreeNode* root = build({ 1,-2,-3,1,3,-2,null,-1 });

    auto result = maxPathSum(root);

    return 0;
}