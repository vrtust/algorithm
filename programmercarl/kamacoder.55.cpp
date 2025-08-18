#include<iostream>

using namespace std;

int main() {
    string s = "abcdefg";
    int k = 2;

    int left = 0;
    int right = s.size() - 1;
    while (left < right) {
        swap(s[left], s[right]);
        left++;
        right--;
    }

    left = 0;
    right = k - 1;
    while (left < right) {
        swap(s[left], s[right]);
        left++;
        right--;
    }

    left = k;
    right = s.size() - 1;
    while (left < right) {
        swap(s[left], s[right]);
        left++;
        right--;
    }

    return 0;
}