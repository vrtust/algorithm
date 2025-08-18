#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
#include<deque>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    // 超时
    // vector<int> result;
    // stack<int> stack_nums;

    // if (nums.size() <= k) {
    //     int maxnum = -9999999;
    //     for (int num : nums) {
    //         maxnum = max(maxnum, num);
    //     }
    //     result.push_back(maxnum);
    //     return result;
    // }

    // int n = 0;
    // int m = nums.size() - k + 1;

    // for (int i = 0; i < m; i++) {
    //     n = k;
    //     int maxnum = -9999999;
    //     while (n--) {
    //         stack_nums.push(nums.back());
    //         maxnum = max(maxnum, nums.back());
    //         nums.pop_back();
    //     }
    //     while (stack_nums.size() > 1) {
    //         nums.push_back(stack_nums.top());
    //         stack_nums.pop();
    //     }
    //     stack_nums.pop();
    //     result.push_back(maxnum);
    // }

    // vector<int> final_result;
    // while (!result.empty()) {
    //     final_result.push_back(result.back());
    //     result.pop_back();
    // }

    // return final_result;

    vector<int> result;
    deque<int> dq;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        if (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        while (!dq.empty() && nums[dq.back()] <= nums[i]) {
            dq.pop_back();
        }

        dq.push_back(i);

        if (i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }

    return result;
}

int main() {
    vector<int> tokens = { 1,3,-1,-3,5,3,6,7 };
    maxSlidingWindow(tokens, 3);
}