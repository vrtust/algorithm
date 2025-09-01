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

void traversal(TreeNode* root, vector<TreeNode*>& nodes) {
    if (root == nullptr) {
        return;
    }

    nodes.push_back(root);
    traversal(root->left, nodes);
    traversal(root->right, nodes);
}

void flatten(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    vector<TreeNode*> nodes;
    traversal(root, nodes);

    for (int i = 0; i < nodes.size() - 1; i++) {
        nodes[i]->left = nullptr;
        nodes[i]->right = nodes[i + 1];
    }
}

int main() {
    TreeNode* root = build({ 1,2,5,3,4,null,6 });

    flatten(root);

    return 0;
}