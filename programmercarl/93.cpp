#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>

using namespace std;

vector<string> restoreIpAddresses(string s) {
    vector<string> result;
    if (s.size() < 4 || s.size() > 12) return result;
    
    string path;
    backtracking(s, 0, 0, path, result);
    return result;
}

void backtracking(const string& s, int start, int part, string& path, vector<string>& result) {
    if (part == 4) {
        if (start == s.size()) {
            result.push_back(path.substr(0, path.size() - 1)); // 移除最后的点
        }
        return;
    }
    
    for (int len = 1; len <= 3 && start + len <= s.size(); ++len) {
        string segment = s.substr(start, len);
        
        // 检查当前段是否有效
        if ((len > 1 && segment[0] == '0') || stoi(segment) > 255) continue;
        
        string originalPath = path;
        path += segment + ".";
        backtracking(s, start + len, part + 1, path, result);
        path = originalPath; // 回溯
    }
}

// vector<string> restoreIpAddresses(string s) {
//     vector<string> result;
//     int n = s.size();
    
//     // 快速排除不可能的情况
//     if (n < 4 || n > 12) return result;
    
//     // 直接遍历所有可能的三段分割点
//     for (int a = 1; a <= 3 && a < n; ++a) {
//         for (int b = a + 1; b <= a + 3 && b < n; ++b) {
//             for (int c = b + 1; c <= b + 3 && c < n; ++c) {
//                 // 检查第四段长度是否合法
//                 if (n - c > 3) continue;
                
//                 string s1 = s.substr(0, a);
//                 string s2 = s.substr(a, b - a);
//                 string s3 = s.substr(b, c - b);
//                 string s4 = s.substr(c);
                
//                 // 检查每段是否有效
//                 if (isValid(s1) && isValid(s2) && isValid(s3) && isValid(s4)) {
//                     result.push_back(s1 + "." + s2 + "." + s3 + "." + s4);
//                 }
//             }
//         }
//     }
    
//     return result;
// }

// bool isValid(const string& s) {
//     if (s.empty() || s.size() > 3) return false;
//     if (s.size() > 1 && s[0] == '0') return false;
//     int num = 0;
//     for (char c : s) {
//         if (!isdigit(c)) return false;
//         num = num * 10 + (c - '0');
//     }
//     return num <= 255;
// }

int main() {
    string s = "25525511135";
    restoreIpAddresses(s);
}