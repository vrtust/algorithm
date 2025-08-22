#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<stack>
#include<unordered_set>
#include<queue>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> result;
    deque<int> deq;

    for (int i = 0; i < nums.size(); i++) {
        if (i < k - 1) {
            while (!deq.empty() && nums[deq.front()] <= nums[i]) {
                deq.pop_front();
            }
            while (!deq.empty() && nums[deq.back()] <= nums[i]) {
                deq.pop_back();
            }
            deq.push_back(i);
        } else {
            while (!deq.empty() && nums[deq.front()] <= nums[i]) {
                deq.pop_front();
            }
            while (!deq.empty() && nums[deq.back()] <= nums[i]) {
                deq.pop_back();
            }
            deq.push_back(i);

            if (deq.front() == i - k) {
                deq.pop_front();
            }
            result.push_back(nums[deq.front()]);
        }
    }

    return result;
}

int main() {
    vector<int> nums = { 1,3,1,2,0,5 };
    int k = 3;
    auto result = maxSlidingWindow(nums, k);

    return 0;
}