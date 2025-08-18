#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
public:
    stack<int> stack_in;
    stack<int> stack_out;

    MyQueue() {

    }

    void push(int x) {
        stack_in.push(x);
    }

    int pop() {
        if (stack_out.empty()) {
            while (!stack_in.empty()) {
                stack_out.push(stack_in.top());
                stack_in.pop();
            }
        }
        int result = stack_out.top();
        stack_out.pop();
        return result;
    }

    int peek() {
        if (stack_out.empty()) {
            while (!stack_in.empty()) {
                stack_out.push(stack_in.top());
                stack_in.pop();
            }
        }
        return stack_out.top();
    }

    bool empty() {
        if(stack_in.empty()&&stack_out.empty()){
            return true;
        }else{
            return false;
        }
        stack_in.emplace();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main() {
    MyQueue* obj = new MyQueue();
    obj->push(1);
    obj->push(2);
    int param_1 = obj->peek();
    int param_2 = obj->pop();
    bool param_3 = obj->empty();
}