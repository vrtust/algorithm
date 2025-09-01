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

TreeNode* buildBST(vector<int>& nums, TreeNode* root, int begin, int end) {
    if (begin > end) {
        return nullptr;
    }

    int mid = (end + begin) / 2;
    root = new TreeNode(nums[mid]);
    root->left = buildBST(nums, root, begin, mid - 1);
    root->right = buildBST(nums, root, mid + 1, end);

    return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    TreeNode* result;
    result = buildBST(nums, result, 0, nums.size() - 1);

    return result;
}

int main() {
    // TreeNode* root = build({ 3,9,20,null,null,15,7 });
    vector<int> nums = { -10,-3,0,5,9 };

    auto result = sortedArrayToBST(nums);

    return 0;
}