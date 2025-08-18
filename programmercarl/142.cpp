#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* detectCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    
    while(fast!=nullptr&&fast->next!=nullptr){
        fast = fast->next->next;
        slow = slow->next;
        if(slow == fast){
            ListNode* index1 = head;
            ListNode* index2 = slow;
            while(index1 != index2){
                index1 = index1->next;
                index2 = index2->next;
            }
            return index1;
        }
    }

    return nullptr;
}

int main() {
    ListNode* headA = nullptr;
    vector<int> A = { 3,2,0,-4 };
    ListNode* pos = nullptr;
    ListNode* temp = nullptr;
    for (int i = 0; i < 4; i++) {
        ListNode* newNode = new ListNode(A[i]);
        if (headA == nullptr) {
            headA = newNode;
            temp = newNode;
        }
        temp->next = newNode;
        temp = temp->next;
        if (i == 1) {
            pos = newNode;
        }
        if (i == 3) {
            temp->next = pos;
        }
    }

    ListNode* result = detectCycle(headA);
    // while (result) {
    //     cout << result->val << " ";
    //     result = result->next;
    // }
    cout << result->val << " ";
    cout << endl;

}