#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<stack>
#include<unordered_set>
#include<queue>
#include<stack>
#include<set>

using namespace std;

struct ListNode {
    int key;
    int val;
    ListNode* next;
    ListNode* prev;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, int y) : key(x), val(y), next(nullptr), prev(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* build(vector<int> nums) {
    ListNode* head = new ListNode(nums[0]);
    ListNode* final_head = head;
    for (int i = 1; i < nums.size(); i++) {
        head->next = new ListNode(nums[i]);
        head = head->next;
    }
    return final_head;
}

class LRUCache {
public:
    int cap;
    int cnt;
    unordered_map<int, ListNode*> hash;
    ListNode* head;
    ListNode* tail;

    LRUCache(int capacity) {
        cap = capacity;
        cnt = 0;
        head = new ListNode(0);
        tail = head;
    }

    int get(int key) {
        if (hash.count(key) == 0) return -1;

        if (tail != hash[key]) {
            hash[key]->prev->next = hash[key]->next;
            if (hash[key]->next != nullptr) {
                hash[key]->next->prev = hash[key]->prev;
            }

            tail->next = hash[key];
            hash[key]->prev = tail;
            tail = tail->next;
            tail->next = nullptr;
        }

        return hash[key]->val;
    }

    void put(int key, int value) {
        if (hash.count(key) > 0) {
            hash[key]->val = value;
            get(key);
        } else {
            ListNode* node = new ListNode(key, value);
            node->prev = tail;
            tail->next = node;
            tail = tail->next;

            hash[key] = node;
            cnt++;
            if (cnt > cap) {
                ListNode* lru = head->next;
                hash.erase(lru->key);
                if (lru->next != nullptr) {
                    lru->next->prev = lru->prev;
                }
                lru->prev->next = lru->next;
                cnt--;
            }
        }
    }
};

int main() {
    LRUCache* lRUCache = new LRUCache(2);
    lRUCache->put(1, 1); // 缓存是 {1=1}
    lRUCache->put(2, 2); // 缓存是 {1=1, 2=2}
    cout << lRUCache->get(1) << endl;    // 返回 1
    lRUCache->put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
    cout << lRUCache->get(2) << endl;    // 返回 -1 (未找到)
    lRUCache->put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
    cout << lRUCache->get(1) << endl;    // 返回 -1 (未找到)
    cout << lRUCache->get(3) << endl;    // 返回 3
    cout << lRUCache->get(4) << endl;    // 返回 4

    return 0;
}