#include <iostream>

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        // records the next node that needs to be populated for a given level
        conn(root);
        return root;
    }

    // O(1) space solution
    void conn(Node *curr) {
        if (!curr)
            return;

        // connect children
        if (curr->left) {
            // connect left child
            curr->left->next = curr->right;

            // connect right child
            if (curr->next) {
                curr->right->next = curr->next->left;
            }
        }

        conn(curr->left);
        conn(curr->right);
    }
};
