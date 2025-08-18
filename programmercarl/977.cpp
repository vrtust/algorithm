#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<int> sortedSquares(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n);

    int i = 0;
    int j = n - 1;

    for (int p = n - 1;p >= 0; p--) {
        if (-nums[i] > nums[j]) {
            result[p] = nums[i] * nums[i];
            i++;
        } else {
            result[p] = nums[j] * nums[j];
            j--;
        }
    }

    return result;
}

int main() {
    vector<int> nums = { -4,-1,0,3,10 };
    vector<int> target_nums = { 0,1,9,16,100 };

    vector<int> result = sortedSquares(nums);

    for (int i = 0; i < nums.size(); i++) {
        if (result[i] != target_nums[i]) {
            cout << "error, result[" << i << "]: " << result[i] << endl;
        }
    }


    return 0;
}