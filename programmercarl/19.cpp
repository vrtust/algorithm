#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0, head);
    ListNode* slow = dummy;
    ListNode* fast = dummy;

    for (int i = 0; i <= n && fast != nullptr; i++) {
        fast = fast->next;
    }

    while (fast != nullptr) {
        slow = slow->next;
        fast = fast->next;
    }

    ListNode* temp = slow->next;
    slow->next = temp->next;
    if (temp == head) {
        head = temp->next;
    }
    delete temp;
    return head;
}

int main() {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int i = 0; i < 5; i++) {
        ListNode* newNode = new ListNode(i + 1);
        if (head == nullptr) {
            head = newNode;
        } else {
            tail->next = newNode;
        }
        tail = newNode;
    }

    ListNode* result = removeNthFromEnd(head, 2);
    while (result) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;

}