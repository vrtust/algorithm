#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* swapPairs(ListNode* head) {
    if (head == nullptr) return nullptr;
    ListNode* dummy = new ListNode(0);
    ListNode* preNode = dummy;
    ListNode* currentNode = head;
    ListNode* nextNode = head->next;
    while (nextNode != nullptr) {
        preNode->next = nextNode;
        currentNode->next = nextNode->next;
        nextNode->next = currentNode;
        if (currentNode == head) {
            head = nextNode;
        }
        if (currentNode->next == nullptr) {
            break;
        }
        preNode = currentNode;
        currentNode = currentNode->next;
        nextNode = currentNode->next;
    }
    delete dummy;
    return head;
}

int main() {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int i = 0; i < 4; i++) {
        ListNode* newNode = new ListNode(i + 1);
        if (head == nullptr) {
            head = newNode;
        } else {
            tail->next = newNode;
        }
        tail = newNode;
    }

    ListNode* result = swapPairs(head);
    while (result) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;

}