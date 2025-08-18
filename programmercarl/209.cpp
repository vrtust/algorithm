#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    int sum = 0;
    int left = 0;
    int result = pow(10, 9);
    for (int right = 0; right < n; right++) {
        sum += nums[right];
        while (sum >= target) {
            result = result < (right - left + 1) ? result : (right - left + 1);
            sum -= nums[left++];
        }
    }
    return result == pow(10, 9) ? 0 : result;
}

int main() {
    vector<int> nums = { 12,28,83,4,25,26,25,2,25,25,25,12 };
    int target = 213;
    int len = 8;

    int result = minSubArrayLen(target, nums);
    if (result != len) {
        cout << len << endl;
    }

    return 0;
}