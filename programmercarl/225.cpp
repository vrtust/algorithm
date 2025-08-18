#include <iostream>
#include <list>

using namespace std;

class MyStack {
public:
    list<int> list_main;
    list<int> list_back;

    MyStack() {

    }

    void push(int x) {
        list_main.push_back(x);
    }

    int pop() {
        int result = 0;
        while (!list_main.empty()) {
            result = list_main.front();
            if (list_main.size() != 1) {
                list_back.push_back(list_main.front());

            }
            list_main.pop_front();
        }

        while (!list_back.empty()) {
            list_main.push_back(list_back.front());
            list_back.pop_front();
        }

        return result;
    }

    int top() {
        int result = this->pop();
        list_main.push_back(result);
        return result;
    }

    bool empty() {
        if (list_main.size() == 0) {
            return true;
        } else {
            return false;
        }
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
    MyStack* obj = new MyStack();
    obj->push(1);
    obj->push(2);
    int param_1 = obj->top();
    int param_2 = obj->pop();
    bool param_3 = obj->empty();
}