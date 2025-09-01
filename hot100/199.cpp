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

vector<int> rightSideView(TreeNode* root) {
    if (root == nullptr) {
        return {};
    }

    queue<TreeNode*> que;
    que.push(root);
    vector<int> result;

    while (!que.empty()) {
        int n = que.size();
        int lastNodeVal = -101;
        for (int i = 0; i < n; i++) {
            TreeNode* cur = que.front();
            que.pop();
            lastNodeVal = cur->val;
            if (cur->left != nullptr) que.push(cur->left);
            if (cur->right != nullptr) que.push(cur->right);
        }
        if (lastNodeVal != -101) result.push_back(lastNodeVal);
    }

    return result;
}

int main() {
    TreeNode* root = build({ 1,2,3,null,5,null,4 });

    auto result = rightSideView(root);

    return 0;
}