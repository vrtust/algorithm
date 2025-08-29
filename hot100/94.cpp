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
        }
        i++;

        if (i < n && nums[i] != -1000) {
            cur->right = new TreeNode(nums[i]);
        }
        i++;
    }

    return root;
}

void dfs(TreeNode* root, vector<int>& result) {
    if (root == nullptr) return;

    if (root->left != nullptr) dfs(root->left, result);
    result.push_back(root->val);
    if (root->right != nullptr) dfs(root->right, result);
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    dfs(root, result);

    return result;
}

int main() {
    TreeNode* root = build({ 1,-1000,2,3 });

    auto result = inorderTraversal(root);

    return 0;
}