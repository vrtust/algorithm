#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<stack>
#include<unordered_set>
#include<queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    int lenA = 0;
    int lenB = 0;

    ListNode* tempA = headA;
    while (tempA != nullptr) {
        lenA++;
        tempA = tempA->next;
    }

    ListNode* tempB = headB;
    while (tempB != nullptr) {
        lenB++;
        tempB = tempB->next;
    }

    int diff = 0;
    if (lenA >= lenB) {
        tempA = headA;
        tempB = headB;
        diff = lenA - lenB;
    } else {
        tempA = headB;
        tempB = headA;
        diff = lenB - lenA;
    }

    while (diff--) {
        tempA = tempA->next;
    }

    while (tempA != tempB) {
        tempA = tempA->next;
        tempB = tempB->next;
    }
    return tempA;
}

ListNode* build(vector<int> nums) {
    ListNode* head = new ListNode(nums[0]);
    ListNode* final_head = head;
    for (int i = 1; i < nums.size(); i++) {
        head->next = new ListNode(nums[i]);
        head = head->next;
    }
    return final_head;
}

int main() {
    ListNode* headA = build({ 4,1 });
    ListNode* headB = build({ 5,6,1 });
    ListNode* tail = build({ 8,4,5 });

    ListNode* tempA = headA;
    ListNode* tempB = headB;

    while (tempA->next != nullptr) {
        tempA = tempA->next;
    }
    tempA->next = tail;

    while (tempB->next != nullptr) {
        tempB = tempB->next;
    }
    tempB->next = tail;

    auto result = getIntersectionNode(headA, headB);

    return 0;
}