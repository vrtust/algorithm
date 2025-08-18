#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

TreeNode* traversal(vector<int>& inorder, int inorderBegin, int inorderEnd, vector<int>& postorder, int postorderBegin, int postorderEnd) {
    if (postorderBegin == postorderEnd) return nullptr;

    int root_val = postorder[postorderEnd - 1];
    TreeNode* root = new TreeNode(root_val);

    int index;
    for (index = inorderBegin; index < inorderEnd - 1; index++) {
        if (inorder[index] == root_val) {
            break;
        }
    }

    int leftInorderBegin = inorderBegin;
    int leftInorderEnd = index;
    int rightInorderBegin = index + 1;
    int rightInorderEnd = inorderEnd;

    int leftPostorderBegin = postorderBegin;
    int leftPostorderEnd = postorderBegin + index - inorderBegin;
    int rightPostorderBegin = postorderBegin + index - inorderBegin;
    int rightPostorderEnd = postorderEnd - 1;

    root->left = traversal(inorder, leftInorderBegin, leftInorderEnd, postorder, leftPostorderBegin, leftPostorderEnd);
    root->right = traversal(inorder, rightInorderBegin, rightInorderEnd, postorder, rightPostorderBegin, rightPostorderEnd);

    return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if (inorder.size() == 0 || postorder.size() == 0) return nullptr;
    return traversal(inorder, 0, inorder.size(), postorder, 0, postorder.size());
}

int main() {
    vector<int> inorder = { 9,3,15,20,7 };
    vector<int> postorder = { 9,15,7,20,3 };

    buildTree(inorder, postorder);
}