#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>
#include<stack>

using namespace std;

int trap(vector<int>& height) {
    // vector<int> greater_height(height.size(), -1);
    // vector<int> greatest_height(height.size(), -1);
    // stack<int> st;

    // for (int i = 0; i < height.size(); i++) {
    //     while (st.size() > 0 && height[i] >= height[st.top()]) {
    //         greater_height[st.top()] = i;
    //         st.pop();
    //     }
    //     st.push(i);
    // }

    // int max_index = height.size() - 1;
    // for (int i = height.size() - 1; i >= 0; i--) {
    //     if (height[i] > height[max_index]) {
    //         max_index = i;
    //     }
    //     greatest_height[i] = max_index;
    // }

    // int last = 0;
    // int result = 0;
    // for (int i = 0; i < height.size(); i++) {
    //     if (greater_height[i] == -1) {
    //         if (i + 1 < height.size()) {
    //             last = greatest_height[i + 1];
    //         }
    //         continue;
    //     } else if (height[i] > height[last]) {
    //         last = i;
    //         continue;
    //     }

    //     result += height[last] - height[i];
    // }

    // return result;

    // 解2
    // if (height.size() < 3) return 0;
    // vector<int> max_right(height.size(), 0);
    // vector<int> max_left(height.size(), 0);

    // max_left[0] = height[0];
    // for (int i = 1; i < height.size(); i++) {
    //     max_left[i] = max(max_left[i - 1], height[i]);
    // }

    // max_right[height.size() - 1] = height[height.size() - 1];
    // for (int i = height.size() - 2; i >= 0; i--) {
    //     max_right[i] = max(max_right[i + 1], height[i]);
    // }

    // int result = 0;
    // for (int i = 0; i < height.size(); i++) {
    //     result += max(0, min(max_left[i], max_right[i]) - height[i]);
    // }

    // return result;

    // 解3
    stack<int> st;
    int result = 0;
    st.push(0);
    for (int i = 1; i < height.size(); i++) {
        while (!st.empty() && height[i] > height[st.top()]) {
            int mid = st.top();
            st.pop();
            if (!st.empty()) {
                int h = min(height[st.top()], height[i]) - height[mid];
                int w = i - st.top() - 1;
                result += h * w;
            }
        }
        st.push(i);
    }

    return result;
}

int main() {
    vector<int> height = { 0,1,0,2,1,0,1,3,2,1,2,1 };

    auto result = trap(height);
}