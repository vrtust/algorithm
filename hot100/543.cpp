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

int dfs(TreeNode* root, vector<int>& len, int height) {
    if (root == nullptr) {
        return height;
    }

    height++;
    int left = height;
    int right = height;
    if (root->left != nullptr)
        left = dfs(root->left, len, height);
    if (root->right != nullptr)
        right = dfs(root->right, len, height);

    int maxHeight = max(left, right);
    int curLen = left - height + right - height;
    len.push_back(max(maxHeight-1, curLen));

    return maxHeight;
}

int diameterOfBinaryTree(TreeNode* root) {
    vector<int> len;
    int result = dfs(root, len, 0);

    int maxLen = 0;
    for (int i = 0; i < len.size(); i++) {
        maxLen = max(maxLen, len[i]);
    }

    return max(result - 1, maxLen);
}

int main() {
    TreeNode* root = build({ 1,2,3,4,5 });

    auto result = diameterOfBinaryTree(root);

    return 0;
}