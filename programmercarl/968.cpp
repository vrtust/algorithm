#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<unordered_map>
#include<algorithm>
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

int result;

// 0: 无覆盖
// 1: 摄像头
// 2: 覆盖
int traversal(TreeNode* root) {
    if (root == nullptr) return 2;

    int left = traversal(root->left);
    int right = traversal(root->right);

    if (left == 2 && right == 2) return 0;
    if (left == 0 || right == 0) {
        result++;
        return 1;
    }
    if (left == 1 || right == 1) return 2;
    return -1;
}

int minCameraCover(TreeNode* root) {
    result = 0;
    if (traversal(root) == 0) {
        result++;
    }
    return result;

    // if (root->left == nullptr && root->right == nullptr) return 1;
    // int count = 0;
    // int depth = 0;
    // vector<int> record;
    // TreeNode* node = root;

    // deque<TreeNode*> dq;
    // dq.push_back(node);

    // vector<vector<TreeNode*>> layers;
    // unordered_map<TreeNode*, int> watched_nodes;

    // while (!dq.empty()) {
    //     int size = dq.size();
    //     record.push_back(size);
    //     vector<TreeNode*> layer;
    //     for (int i = 0; i < size; i++) {
    //         TreeNode* cur_node = dq.front();
    //         dq.pop_front();
    //         layer.push_back(cur_node);

    //         if (cur_node->left != nullptr) dq.push_back(cur_node->left);
    //         if (cur_node->right != nullptr) dq.push_back(cur_node->right);
    //     }
    //     layers.push_back(layer);
    //     depth++;
    // }

    // for (int i = depth - 2; i >= 0; i--) {
    //     for (auto& cur_node : layers[i]) {
    //         if ((cur_node->left != nullptr && watched_nodes.count(cur_node->left) > 0 && watched_nodes[cur_node->left] == 1) || (cur_node->right != nullptr && watched_nodes.count(cur_node->right) > 0 && watched_nodes[cur_node->right] == 1)) {
    //             if ((cur_node->left != nullptr && watched_nodes.count(cur_node->left) <= 0) || (cur_node->right != nullptr && watched_nodes.count(cur_node->right) <= 0)) {
    //                 watched_nodes.insert({ cur_node, 1 });
    //                 count++;
    //             } else {
    //                 watched_nodes.insert({ cur_node, 0 });
    //             }

    //             continue;
    //         }

    //         if (i != 0 && ((cur_node->left != nullptr && cur_node->right == nullptr && watched_nodes.count(cur_node->left) > 0 && watched_nodes[cur_node->left] == 0) || (cur_node->right != nullptr && cur_node->left == nullptr && watched_nodes.count(cur_node->right) > 0 && watched_nodes[cur_node->right] == 0))) {
    //             continue;
    //         }

    //         bool has_child = false;
    //         if (cur_node->left != nullptr && watched_nodes.count(cur_node->left) <= 0) {
    //             watched_nodes.insert({ cur_node->left, 0 });
    //             has_child = true;
    //         }
    //         if (cur_node->right != nullptr && watched_nodes.count(cur_node->right) <= 0) {
    //             watched_nodes.insert({ cur_node->right, 0 });
    //             has_child = true;
    //         }

    //         if (has_child) {
    //             watched_nodes.insert({ cur_node, 1 });
    //             count++;
    //         }
    //     }
    // }

    // return count;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    // root->right = new TreeNode(3);
    // root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(3);
    // root->right->right = new TreeNode(4);
    // root->right->right->right = new TreeNode(0);
    // root->right->right = new TreeNode(0);
    root->left->right->left = new TreeNode(4);
    root->left->right->right = new TreeNode(5);
    // root->left->right->left->right = new TreeNode(5);
    // root->left->right->left->right->left = new TreeNode(6);
    root->left->right->left->left = new TreeNode(6);
    root->left->right->left->left->left = new TreeNode(7);

    minCameraCover(root);
}