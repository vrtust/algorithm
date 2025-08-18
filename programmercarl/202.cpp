#include<iostream>
#include<array>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<unordered_map>

using namespace std;

bool isHappy(int n) {
    int result = n;
    unordered_set<int> record;

    while (result != 1) {
        int num = result;
        record.insert(num);
        result = 0;
        while (num != 0) {
            result += (num % 10) * (num % 10);
            num = num/10;
        }
        if(record.count(result)>0){
            return false;
        }
    }
    return true;
}

int main() {
    isHappy(2);
}