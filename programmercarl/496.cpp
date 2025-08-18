#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>
#include<stack>

using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> greaterElement;
    vector<int> result(nums1.size(), -1);
    stack<int> st;
    st.push(0);

    for (int i = 1; i < nums2.size(); i++) {
        while (!st.empty() && nums2[i] > nums2[st.top()]) {
            greaterElement[nums2[st.top()]] = nums2[i];
            st.pop();
        }
        st.push(i);
    }

    for (int i = 0; i < nums1.size(); i++) {
        if(greaterElement[nums1[i]] > 0) result[i] = greaterElement[nums1[i]];
        else result[i] = -1;
    }

    return result;
}

int main() {
    vector<int> nums1 = { 4,1,2 };
    vector<int> nums2 = { 1,3,4,2 };

    auto result = nextGreaterElement(nums1, nums2);
}