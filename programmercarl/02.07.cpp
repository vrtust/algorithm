#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    ListNode* tempA = headA;
    ListNode* tempB = headB;
    ListNode* result = nullptr;
    int countA = 0;
    int countB = 0;
    int len = 0;

    while (tempA != nullptr) {
        countA++;
        tempA = tempA->next;
    }
    while (tempB != nullptr) {
        countB++;
        tempB = tempB->next;
    }

    tempA = headA;
    tempB = headB;
    if (countA >= countB) {
        len = countA - countB;
        while (len--) {
            tempA = tempA->next;
        }
    } else {
        len = countB - countA;
        while (len--) {
            tempB = tempB->next;
        }
    }

    while (tempA != nullptr) {
        if (tempA == tempB) {
            result = tempA;
            break;
        }
        tempA = tempA->next;
        tempB = tempB->next;
    }

    return result;
}

int main() {
    ListNode* headA = nullptr;
    vector<int> A = { 4,1,8,4,5 };
    for (int i = 0; i < 5; i++) {
        ListNode* newNode = new ListNode(i + 1);
        if (headA == nullptr) {
            headA = newNode;
        }
    }

    ListNode* headB = nullptr;
    vector<int> B = { 5,0,1,8,4,5 };
    for (int i = 0; i < 5; i++) {
        ListNode* newNode = new ListNode(i + 1);
        if (headB == nullptr) {
            headB = newNode;
        }
    }

    ListNode* result = getIntersectionNode(headA, headB);
    while (result) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;

}