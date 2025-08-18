#include<iostream>

using namespace std;

class MyLinkedList {
public:
    struct ListNode {
        int val;
        ListNode* next;
        ListNode() : val(0), next(nullptr) {};
        ListNode(int x) : val(x), next(nullptr) {};
        ListNode(int x, ListNode* node) : val(x), next(node) {};
    };

    ListNode* head;
    ListNode* tail;
    int size;

    MyLinkedList() : head(nullptr), tail(nullptr), size(0) {

    }

    int get(int index) {
        if (index < 0 || index >= size) return -1;
        int i = 0;
        ListNode* result_node = head;
        while (i <= index && result_node != nullptr) {
            if (i == index) {
                return result_node->val;
            }
            result_node = result_node->next;
            i++;
        }
        return -1;
    }

    void addAtHead(int val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = head;
        head = newNode;
        if (tail == nullptr) {
            tail = newNode;
        }
        size++;
    }

    void addAtTail(int val) {
        ListNode* newNode = new ListNode(val);
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) return;
        int i = 0;
        ListNode* curNode = head;
        ListNode* dummy = new ListNode(0, head);
        ListNode* preNode = dummy;
        ListNode* newNode = new ListNode(val);
        while (i <= index) {
            if (i == index) {
                preNode->next = newNode;
                newNode->next = curNode;
                if (newNode->next == nullptr) {
                    tail = newNode;
                }
            } else {
                preNode = curNode;
                curNode = curNode->next;
            }
            i++;
        }
        size++;
        head = dummy->next;
        delete dummy;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;
        int i = 0;
        ListNode* curNode = head;
        ListNode* dummy = new ListNode(0, head);
        ListNode* preNode = dummy;
        while (i <= index && curNode != nullptr) {
            if (i == index) {
                preNode->next = curNode->next;
                if (curNode == tail) {
                    tail = preNode;
                }
                delete curNode;
                curNode = preNode->next;
            } else {
                preNode = curNode;
                curNode = curNode->next;
            }
            i++;
        }
        size--;
        head = dummy->next;
        delete dummy;
    }
};

int main() {
    MyLinkedList list;
    list.addAtHead(7);
    list.addAtTail(2);
    list.addAtTail(1);
    list.addAtIndex(3, 0);    // 1->2->3
    list.deleteAtIndex(2);
    list.addAtHead(6);
    list.addAtTail(4);
    cout << list.get(4) << endl;
    list.addAtHead(4);
    list.addAtIndex(5, 0);
    list.addAtHead(6);
    return 0;
}