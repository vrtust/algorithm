#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<stack>

using namespace std;

int trap(vector<int>& height) {
    // stack<int> st;
    // int result = 0;
    // st.push(0);

    // for (int i = 1; i < height.size(); i++) {
    //     while (st.size() > 0 && height[i] >= height[st.top()]) {
    //         int cur = st.top();
    //         st.pop();
    //         if (st.size() > 0) {
    //             result += (min(height[i], height[st.top()]) - height[cur]) * (i - st.top() - 1);
    //         }
    //     }
    //     st.push(i);
    // }

    // return result;

    // if (height.size() < 3) return 0;
    // vector<int> left(height.size(), 0);
    // for (int i = 1; i < height.size(); i++) {
    //     left[i] = max(left[i - 1], height[i - 1]);
    // }

    // vector<int> right(height.size(), 0);
    // for (int i = height.size() - 2; i >= 0; i--) {
    //     right[i] = max(right[i + 1], height[i + 1]);
    // }

    // int result = 0;
    // for (int i = 1; i < height.size(); i++) {
    //     result += max(0, min(left[i], right[i]) - height[i]);
    // }
    // return result;

    int leftMax = 0;
    int rightMax = 0;
    int result = 0;

    int l = 0;
    int r = height.size() - 1;

    while (l < r) {
        if (height[l] <= height[r]) {
            if (height[l] >= leftMax) leftMax = height[l];
            else result += leftMax - height[l];
            l++;
        } else {
            if (height[l] > height[r]) {
                if (height[r] >= rightMax) rightMax = height[r];
                else result += rightMax - height[r];
                r--;
            }
        }
    }

    return result;
}

int main() {
    vector<int> height = { 0,1,0,2,1,0,1,3,2,1,2,1 };
    auto result = trap(height);

    return 0;
}