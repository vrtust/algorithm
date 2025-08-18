#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

std::unordered_map<int, int> inorder_map;

TreeNode* traversal(vector<int>& preorder, int preorderBegin, int preorderEnd, vector<int>& inorder, int inorderBegin, int inorderEnd) {
    if (preorderBegin == preorderEnd) return nullptr;

    int root_val = preorder[preorderBegin];
    TreeNode* root = new TreeNode(root_val);

    // int index;
    // for (index = inorderBegin; index < inorderEnd; index++) {
    //     if (inorder[index] == root_val) {
    //         break;
    //     }
    // }
    int index = inorder_map[root_val];

    int leftInorderBegin = inorderBegin;
    int leftInorderEnd = index;
    int leftPreorderBegin = preorderBegin + 1;
    int leftPreorderEnd = leftPreorderBegin + index - inorderBegin;

    int rightInorderBegin = index + 1;
    int rightInorderEnd = inorderEnd;
    int rightPreorderBegin = leftPreorderEnd;
    int rightPreorderEnd = preorderEnd;

    root->left = traversal(preorder, leftPreorderBegin, leftPreorderEnd, inorder, leftInorderBegin, leftInorderEnd);
    root->right = traversal(preorder, rightPreorderBegin, rightPreorderEnd, inorder, rightInorderBegin, rightInorderEnd);

    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if (preorder.size() == 0) return nullptr;

    for (int i = 0; i < inorder.size(); ++i) {
        inorder_map[inorder[i]] = i;
    }

    return traversal(preorder, 0, preorder.size(), inorder, 0, inorder.size());
}

int main() {
    vector<int> inorder = { 9,3,15,20,7 };
    vector<int> postorder = { 9,15,7,20,3 };

    buildTree(inorder, postorder);
}