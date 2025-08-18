#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {
    }
};

Node* connect(Node* root) {
    vector<vector<int>> result;
    queue<Node*> queue_node;

    if (root != nullptr) {
        queue_node.push(root);
        result.push_back({ root->val });
    }

    while (!queue_node.empty()) {
        int size = queue_node.size();
        Node* last_node = nullptr;
        for (int i = 0; i < size; i++) {
            Node* node = queue_node.front();
            queue_node.pop();
            if (node->left != nullptr) {
                queue_node.push(node->left);
                if (last_node != nullptr) {
                    last_node->next = node->left;
                    last_node = node->left;
                } else {
                    last_node = node->left;
                }
            }
            if (node->right != nullptr) {
                queue_node.push(node->right);
                if (last_node != nullptr) {
                    last_node->next = node->right;
                    last_node = node->right;
                } else {
                    last_node = node->right;
                }
            }
        }
    }

    return root;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    connect(root);
}