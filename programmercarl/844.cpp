#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool backspaceCompare(string s, string t) {
    int i = s.length() - 1;
    int j = t.length() - 1;
    int skip_s = 0;
    int skip_t = 0;

    while (i >= 0 || j >= 0) {
        while (i >= 0) {
            if (s[i] == '#') {
                skip_s++;
                i--;
            } else if (skip_s > 0) {
                skip_s--;
                i--;
            } else {
                break;
            }
        }

        while (j >= 0) {
            if (t[j] == '#') {
                skip_t++;
                j--;
            } else if (skip_t > 0) {
                skip_t--;
                j--;
            } else {
                break;
            }
        }

        if (i >= 0 && j >= 0) {
            if (s[i] != t[j]) {
                return false;
            }
        } else {
            if (i >= 0 || j >= 0) {
                return false;
            }
        }

        i--;
        j--;
    }
    return true;
}

int main() {
    string s = "a#c";
    string t = "b";

    // bool a = backspaceCompare(s, t);

    // cout << "" << endl;

    bool b = backspaceCompare("xywrrmp", "xywrrmu#p");

    // cout << a << endl;
    cout << b << endl;

    return 0;
}