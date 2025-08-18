#include<iostream>

using namespace std;

int strStr(string haystack, string needle) {
    int i = 0;
    while (i < haystack.size()) {
        if (haystack[i] == needle[0]) {
            int count = 0;
            while (count < needle.size() && i + count < haystack.size()) {
                if (haystack[i + count] != needle[count]) {
                    break;
                }
                count++;
            }
            if(count == needle.size()){
                return i;
            }
        }
        i++;
    }
    return -1;
}

int main() {
    string haystack = "sadbutsad";
    string needle = "sad";

    strStr(haystack, needle);

    return 0;
}