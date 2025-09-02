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

bool dfs(TreeNode* root, TreeNode* target, vector<TreeNode*>& path) {
    if (root == target) {
        path.push_back(root);
        return true;
    } else if (root == nullptr) {
        return false;
    }

    path.push_back(root);
    if (dfs(root->left, target, path) || dfs(root->right, target, path)) {
        return true;
    }
    path.pop_back();

    return false;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    vector<TreeNode*> pathP;
    vector<TreeNode*> pathQ;
    dfs(root, p, pathP);
    dfs(root, q, pathQ);

    int lenP = pathP.size();
    int lenQ = pathQ.size();

    TreeNode* result;
    for (int i = 0; i < lenP && i < lenQ; i++) {
        if (pathP[i] == pathQ[i]) {
            result = pathP[i];
        } else {
            break;
        }
    }

    return result;
}

int main() {
    TreeNode* root = build({ 1,2 });

    auto result = lowestCommonAncestor(root, root, root->left);

    return 0;
}