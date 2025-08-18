#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string s = "a1b2c3";

    int count = 0;
    for (auto c : s) {
        if (c >= '0' && c <= '9') {
            count++;
        }
    }

    int left = s.size() - 1;
    s.resize(s.size() + count * 5);
    int right = s.size() - 1;
    while (left >= 0) {
        if (s[left] >= '0' && s[left] <= '9') {
            s[right--] = 'r';
            s[right--] = 'e';
            s[right--] = 'b';
            s[right--] = 'm';
            s[right--] = 'u';
            s[right--] = 'n';
        } else{
            s[right--] = s[left];
        }
        left--;
    }

    if (s == "anumberbnumbercnumber") {
        cout << "success" << endl;
    }

    return 0;
}