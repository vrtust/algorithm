#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string reverseStr(string s, int k) {
    int count = 0;
    for (int i = 0; i < s.size(); i++) {
        if ((i + 1) % (2 * k) == 0) {
            int left = i - 2 * k + 1;
            int right = i - k;
            while (left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
            count++;
        } else if (i == s.size() - 1 && i + 1 - 2 * k * count < k) {
            int left = 2 * k * count;
            int right = i;
            while (left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        } else if (i == s.size() - 1 && i + 1 - 2 * k * count >= k) {
            int left = 2 * k * count;
            int right = 2 * k * count + k - 1;
            while (left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }
    }
    return s;
}

int main() {
    string s = "abcdefg";
    reverseStr(s, 2);
    return 0;
}