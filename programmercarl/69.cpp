#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int mySqrt(int x) {
    if (x == 0) return 0;
    long left = 0;
    long right = x;
    long result;

    while (left <= right) {
        result = (left + right) / 2;
        if (result * result == (long)x) {
            std::cout << "find, result: " << result << ", left: " << left << ", right: " << right << std::endl;
            return result;
        } else if (result * result > (long)x) {
            right = result - 1;
        } else {
            left = result + 1;
        }
    }

    std::cout << "not find, result: " << result << ", left: " << left << ", right: " << right << std::endl;

    return right;
}

int main() {
    int x = 2147395599;
    int right_result = 46339;
    int result = mySqrt(x);

    if (result == right_result) {
        std::cout << "Right!" << std::endl;
    } else {
        std::cout << "Wrong!" << std::endl;
        std::cout << result << std::endl;
    }
}