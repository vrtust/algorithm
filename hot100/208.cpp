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

class Trie {
public:
    struct Node {
        char letter;
        bool isWord;
        vector<Node*> next;
        Node(char c) : letter(c), next(vector<Node*>(26, nullptr)), isWord(false) {}
    };

    Node* root;

    Trie() {
        root = new Node('A');
    }

    void insert(string word) {
        Node* temp = root;

        for (auto c : word) {
            if (temp->next[c - 'a'] == nullptr) {
                temp->next[c - 'a'] = new Node(c);
            }
            temp = temp->next[c - 'a'];
        }

        return;
    }

    bool search(string word) {
        Node* temp = root;

        for (auto c : word) {
            if (temp->next[c - 'a'] == nullptr) {
                return false;
            }
            temp = temp->next[c - 'a'];
        }

        return temp->isWord;
    }

    bool startsWith(string prefix) {
        Node* temp = root;

        for (auto c : prefix) {
            if (temp->next[c - 'a'] == nullptr) {
                return false;
            }
            temp = temp->next[c - 'a'];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main() {
    Trie* obj = new Trie();
    obj->insert("apple");
    bool param_2 = obj->search("apple");
    bool param_3 = obj->search("app");
    bool param_4 = obj->startsWith("app");
    obj->insert("app");
    bool param_6 = obj->search("app");

    return 0;
}