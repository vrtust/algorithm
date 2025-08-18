#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>
#include<stack>

using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
    vector<int> greaterElement(nums.size(), -1);
    vector<int> result(nums.size(), -1);
    stack<int> st;
    st.push(0);

    for (int i = 1; i < nums.size() * 2; i++) {
        int cur = i % nums.size();
        while (!st.empty() && nums[cur] > nums[st.top()]) {
            greaterElement[st.top() % nums.size()] = nums[cur];
            st.pop();
        }
        if (greaterElement[cur] == -1) st.push(cur);
    }

    for (int i = 0; i < nums.size(); i++) {
        if (greaterElement[i] > 0) result[i] = greaterElement[i];
        else result[i] = -1;
    }

    return result;
}

int main() {
    vector<int> nums = { -1,0 };

    auto result = nextGreaterElements(nums);
}