#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;

int totalFruit(vector<int>& fruits) {
    // 自己想的
    // int n = fruits.size();
    // int left = 0;
    // int A = -1;
    // int B = -1;
    // int lastA = 0;
    // int lastB = 0;
    // int result = 0;
    // for (int right = 0; right < n; right++) {
    //     // cout << "A: " << A << ", lastA: " << lastA << ", countA: " << countA <<
    //     if (A == -1 && fruits[right] != B) {
    //         A = fruits[right];
    //     }
    //     if (B == -1 && fruits[right] != A) {
    //         B = fruits[right];
    //     }
    //     if (A == fruits[right] || B == fruits[right]) {
    //         if (A == fruits[right]) {
    //             lastA = right;
    //         }
    //         if (B == fruits[right]) {
    //             lastB = right;
    //         }
    //         result = max(result, right - left + 1);
    //     } else if (A != -1 && B != -1) {
    //         if (fruits[right - 1] == A) {
    //             left = lastB + 1;
    //             B = fruits[right];
    //             lastB = right;
    //         }
    //         if (fruits[right - 1] == B) {
    //             left = lastA + 1;
    //             A = fruits[right];
    //             lastA = right;
    //         }
    //     }
    // }
    // return result == 0 ? 0 : result;

    // 别人的
    int left = 0;
    unordered_map<int, int> cnt;
    int result = 0;
    for (int right = 0; right < fruits.size(); right++) {
        cnt[fruits[right]]++;
        while (cnt.size() > 2) {
            cnt[fruits[left]]--;
            if (cnt[fruits[left]] == 0) {
                cnt.erase(fruits[left]);
            }
            left++;
        }
        result = max(result, right - left + 1);
    }
    return result;
}

int main() {
    vector<int> nums = { 4,7,7,0,8,3,8,2,5 };
    int target = 3;

    int result = totalFruit(nums);
    if (result != target) {
        cout << "Wrong! result is " << result << endl;
    }

    return 0;
}