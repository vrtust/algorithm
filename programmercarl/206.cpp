struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode* preNode = nullptr;
    ListNode* curNode = head;;
    ListNode* nextNode = nullptr;

    while(curNode!=nullptr){
        nextNode = curNode->next;
        curNode->next = preNode;
        preNode = curNode;
        curNode = nextNode;
    }

    return preNode;
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

    ListNode* result = reverseList(head);
    while (head) {

    }

}