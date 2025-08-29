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

void dfsLeft(TreeNode* root, vector<int>& result) {
    if (root == nullptr) return;

    if (root->left != nullptr) {
        dfsLeft(root->left, result);
    } else {
        result.push_back(null);
    }

    if (root->right != nullptr) {
        dfsLeft(root->right, result);
    } else {
        result.push_back(null);
    }

    result.push_back(root->val);
}

void dfsRight(TreeNode* root, vector<int>& result) {
    if (root == nullptr) return;

    if (root->right != nullptr) {
        dfsRight(root->right, result);
    } else {
        result.push_back(null);
    }

    if (root->left != nullptr) {
        dfsRight(root->left, result);
    } else {
        result.push_back(null);
    }

    result.push_back(root->val);
}


bool isSymmetric(TreeNode* root) {
    if (root == nullptr) return true;

    vector<int> left;
    vector<int> right;
    dfsLeft(root->left, left);
    dfsRight(root->right, right);

    return left == right;
}

int main() {
    TreeNode* root = build({ 1,2,2,3,4,4,3 });

    auto result = isSymmetric(root);

    return 0;
}