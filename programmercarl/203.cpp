#include <iostream>

using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* removeElements(ListNode* head, int val) {
    ListNode* dummpy = new ListNode(0, head);
    ListNode* lastNode = dummpy;
    ListNode* currentNode = head;
    while (currentNode!=nullptr)
    {
        if(currentNode->val == val){
            lastNode->next = currentNode->next;
            delete currentNode;
            currentNode = lastNode->next;
        } else{
            lastNode = currentNode;
            currentNode = currentNode->next;
        }
    }
    ListNode* result = dummpy->next;
    delete dummpy;
    return result;
}

int main() {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int i = 0; i < 6; i++) {
        ListNode* newNode = new ListNode(i + 1);
        if (head == nullptr) {
            head = newNode;
        } else {
            tail->next = newNode;
        }
        tail = newNode;
    }

    removeElements(head, 6);
}