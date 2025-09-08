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
#include<cctype>

using namespace std;

int largestRectangleArea(vector<int>& heights) {
    stack<int> st;
    int result = 0;

    heights.insert(heights.begin(), 0);
    heights.push_back(0);

    st.push(0);

    for (int i = 1; i < heights.size(); i++) {
        while (!st.empty() && heights[i] < heights[st.top()]) {
            int mid = st.top();
            st.pop();

            if (!st.empty()) {
                int w = i - st.top() - 1;
                int h = heights[mid];
                result = max(result, h * w);
            }
        }
        st.push(i);
    }

    return result;
}

int main() {
    vector<int> heights = { 2,1,5,6,2,3 };
    auto result = largestRectangleArea(heights);

    return 0;
}