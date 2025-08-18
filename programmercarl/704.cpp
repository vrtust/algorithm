#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    int result;

    while (left <= right) {
        result = (left + right) / 2;
        if (nums[result] == target) {
            return result;
        } else if (nums[result] > target) {
            right = result - 1;
        } else {
            left = result + 1;
        }
    }

    return -1;
}


int main() {
    vector<int> nums = { -1,0,3,5,9,12 };
    int target = 2;
    int right_result = -1;

    if (search(nums, target) == right_result) {
        std::cout << "Right!" << std::endl;
    } else {
        std::cout << "Wrong!" << std::endl;
    }
}