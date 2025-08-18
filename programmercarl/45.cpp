#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>

using namespace std;

int jump(vector<int>& nums) {
    if (nums.size() == 1) return 0;

    int result = 0;
    int cover = 0;

    for (int i = 0; i <= cover; i++) {
        if (cover < i + nums[i]) {
            result++;
            cover = i + nums[i];

            if (cover >= nums.size() - 1) return result;

            int temp = 0;
            for (int j = i + 1; j <= cover; j++) {
                if (j + nums[j] > temp) {
                    i = j - 1;
                    temp = j + nums[j];
                }
            }
        }
    }

    return result;
}

int main() {
    vector<int> nums = { 7,0,9,6,9,6,1,7,9,0,1,2,9,0,3 };

    jump(nums);
}