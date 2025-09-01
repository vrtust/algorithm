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

TreeNode* build(vector<int>& preorder, vector<int>& inorder,
    int preBegin, int inBegin, int inEnd) {

    if (inBegin > inEnd) {
        return nullptr;
    }

    int pre = preBegin;
    int in = inBegin;
    for (int i = inBegin; i <= inEnd; i++) {
        if (preorder[pre] == inorder[i]) {
            in = i;
            break;
        }
    }

    TreeNode* root = new TreeNode(preorder[pre]);
    root->left = build(preorder, inorder, preBegin + 1, inBegin, in - 1);
    root->right = build(preorder, inorder, preBegin + (in - inBegin) + 1, in + 1, inEnd);

    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    auto result = build(preorder, inorder, 0, 0, inorder.size() - 1);
    return result;
}

int main() {
    // TreeNode* root = build({ 1,2,5,3,4,null,6 });
    vector<int> preorder = { 1,2 };
    vector<int> inorder = { 2,1 };

    auto result = buildTree(preorder, inorder);

    return 0;
}