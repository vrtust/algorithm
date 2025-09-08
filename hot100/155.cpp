#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<stack>
#include<unordered_set>
#include<queue>
#include<stack>
#include<set>

using namespace std;

class MinStack {
public:
    stack<int> nums;
    stack<int> min_nums;
    MinStack() {

    }

    void push(int val) {
        nums.push(val);
        if (min_nums.empty()) {
            min_nums.push(val);
        } else if (val <= min_nums.top()) {
            min_nums.push(val);
        }
    }

    void pop() {
        int n = nums.top();
        nums.pop();
        if (min_nums.top() == n) {
            min_nums.pop();
        }
    }

    int top() {
        return nums.top();
    }

    int getMin() {
        return min_nums.top();
    }
};

int main() {
    MinStack* obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    cout << obj->getMin() << endl;
    obj->pop();
    cout << obj->top() << endl;
    cout << obj->getMin() << endl;

    return 0;
}