#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;

string minWindow(string s, string t) {
    // s过长会报错内存超出
    // unordered_map<char, int> count_s, count_t;
    // for (auto str : t) {
    //     count_t[str]++;
    // }

    // string result = "";
    // int left = 0;
    // int length = pow(10, 5);

    // for (int right = 0; right < s.length(); right++) {
    //     if (count_t.find(s[right]) == count_t.end()) {
    //         continue;
    //     }

    //     count_s[s[right]]++;
    //     int success = 1;
    //     int temp_left = left;

    //     while (success == 1 && left <= right) {
    //         for (auto c : count_t) {
    //             if (count_s.find(c.first) == count_s.end() || count_s[c.first] < c.second) {
    //                 // cout << c.first << endl;
    //                 success = 0;
    //                 break;
    //             }
    //         }
    //         if (success == 1) {
    //             if (length > right - left + 1) {
    //                 length = right - left + 1;
    //                 result = s.substr(left, length);
    //                 // cout << result << endl;
    //             }
    //             if (count_s.find(s[left]) != count_s.end()) {
    //                 count_s[s[left]]--;
    //             }
    //             left++;
    //         }
    //     }
    //     if (left != temp_left) {
    //         left--;
    //         if (count_s.find(s[left]) != count_s.end()) {
    //             count_s[s[left]]++;
    //         }
    //     }
    // }
    // return result;

    vector<int> count_s(128, 0);
    vector<int> count_t(128, 0);

    for (char c : t) {
        count_t[c]++;
    }

    int required = t.length();
    int formed = 0;

    int left = 0;
    int min_left = 0;
    int min_len = pow(5, 10);

    for (int right = 0; right < s.length(); right++) {
        char c = s[right];
        count_s[c]++;

        if (count_t[c] > 0 && count_s[c] <= count_t[c]) {
            formed++;
        }

        while (formed == required && left <= right) {
            char leftchar = count_s[left];
            if (right - left + 1 < min_len) {
                min_len = right - left + 1;
                min_left = left;
            }

            if (count_t[leftchar] > 0 && count_s[leftchar] <= count_t[leftchar]) {
                formed--;
            }
            count_s[leftchar]--;
            left++;
        }
    }
    return min_len == pow(5, 10) ? "" : s.substr(min_left, min_len);
}

int main() {
    string s = "AAOBECODEBANC";
    string t = "ABC";
    string target = "BANC";

    string result = minWindow(s, t);
    if (result != target) {
        cout << "Wrong! result is " << result << endl;
    }

    // cout << s.substr(0, 1) << endl;
    // cout << s.substr(0, 2) << endl;
    // cout << s.substr(1, 2) << endl;
    // cout << s.substr(1, 1) << endl;
    // cout << s.substr(2, 2) << endl;

    return 0;
}