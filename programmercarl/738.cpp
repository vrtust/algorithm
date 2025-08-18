#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>

using namespace std;

int monotoneIncreasingDigits(int n) {
    // while (n > 0) {
    //     bool find = true;
    //     int num = n;
    //     int pre = 1;
    //     while (num != 0) {
    //         if (num % 10 < num / 10 % 10) {
    //             find = false;
    //             break;
    //         }
    //         num = num / 10;
    //     }

    //     if (find) {
    //         return n;
    //     }

    //     n -= n % 10 + 1;
    // }

    // return 0;

    if (n < 10) return n;

    vector<int> record;
    int num = n;
    while (num > 0) {
        record.push_back(num % 10);
        num = num / 10;
    }

    for (int i = 1; i < record.size(); i++) {
        if (record[i - 1] < record[i]) {
            record[i - 1] = 9;
            record[i] -= 1;
            for (int j = 0; j < i - 1; j++) {
                record[j] = 9;
            }
        }
    }

    num = 0;
    long ten = 1;
    for (auto m : record) {
        num += ten * m;
        ten *= 10;
    }

    return num;
}

int main() {
    int n = 1000000000;

    monotoneIncreasingDigits(n);
}