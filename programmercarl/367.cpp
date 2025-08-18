#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

bool isPerfectSquare(int num) {
    long left = 0;
    long right = num;
    long result;

    while (left <= right) {
        result = (left + right) / 2;
        if (result * result == (long)num) {
            std::cout << "find, result: " << result << ", left: " << left << ", right: " << right << std::endl;
            return true;
        } else if (result * result > (long)num) {
            right = result - 1;
        } else {
            left = result + 1;
        }
    }

    std::cout << "not find, result: " << result << ", left: " << left << ", right: " << right << std::endl;

    return false;
}

int main() {
    int num = 16;
    bool right_result = true;
    bool result = isPerfectSquare(num);

    if (result == right_result) {
        std::cout << "Right!" << std::endl;
    } else {
        std::cout << "Wrong!" << std::endl;
        std::cout << result << std::endl;
    }
}