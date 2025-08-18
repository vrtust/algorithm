#include<iostream>
#include<vector>

using namespace std;

bool repeatedSubstringPattern(string s) {
    int n = s.size();
    vector<int> next(n, 0);
    int i = 1;
    for (int j = 0; i < s.size(); i++) {
        while (j > 0 && s[i] != s[j]) {
            j = next[j - 1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        next[i] = j;
    }
    if (next[s.size() - 1] != 0 && s.size() % (s.size() - next[s.size() - 1]) == 0) {
        return true;
    } else {
        return false;
    }
}

int main() {
    string s = "abac";

    repeatedSubstringPattern(s);

    return 0;
}