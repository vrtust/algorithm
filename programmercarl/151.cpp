#include<iostream>

using namespace std;

string reverseWords(string s) {
    int left = 0;
    while (left < s.size() && isspace(s[left])) {
        left++;
    }
    s.erase(0, left);

    int right = s.size() - 1;
    while (right >= 0 && isspace(s[right])) {
        right--;
    }
    s.erase(right + 1);

    int n = s.size();

    for (int i = 0; i < n; i++) {
        left = i + 1;
        right = i;
        while (isspace(s[right]) && isspace(s[right + 1])) {
            right++;
        }
        right++;
        if (left != right) {
            s.erase(left, (right - left));
            n = s.size();
        }
    }

    left = 0;
    right = s.size() - 1;
    while (left < right) {
        swap(s[left], s[right]);
        left++;
        right--;
    }

    left = 0;
    right = 0;
    for (int i = 0; i < s.size() && right < s.size(); i++) {
        right++;
        int temp = 0;
        if (isspace(s[right]) || right == s.size()) {
            temp = right;
            right--;
            while (left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
            left = temp + 1;
            right = temp + 1;
        }
    }


    return s;
}

int main() {
    string s = " oZXvy1g   DQofk    1DC1EoYUN       f      H0ftSoG8hE      Fk      OME2Tb       hbHK       6   OXGN2MhIN      e7      H1Is5g1f8x   450rPmDV    yg5zQ     bKWDpgD 39 Qru7JtXq JGWoo5fFGD    G8  M    b1tczJcE2a   W2    U7Zgb8 rGQvQ6  CH9RSe";
    string result = reverseWords(s);
}