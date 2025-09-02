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

int dfs(TreeNode* root, unordered_map<long long, int>& prefixSum, int targetSum, long long curSum) {
    if (root == nullptr) {
        return 0;
    }

    int count = 0;

    curSum += root->val;
    if (prefixSum.count(curSum - targetSum) > 0) {
        count = prefixSum[curSum - targetSum];
    }

    prefixSum[curSum]++;

    count += dfs(root->left, prefixSum, targetSum, curSum);
    count += dfs(root->right, prefixSum, targetSum, curSum);

    prefixSum[curSum]--;

    return count;
}

int pathSum(TreeNode* root, int targetSum) {
    unordered_map<long long, int> prefixSum;
    prefixSum[0] = 1;

    int count = dfs(root, prefixSum, targetSum, 0);

    return count;
}

int main() {
    TreeNode* root = build({ 10,5,-3,3,2,null,11,3,-2,null,1 });

    auto result = pathSum(root, 8);

    return 0;
}