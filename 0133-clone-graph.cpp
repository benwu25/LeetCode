#include <vector>
#include <list>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }
        // Deep-copy initial node
        Node *n = new Node(node->val);
        if (node->neighbors.size() == 0) {
            return n;
        }
        std::unordered_map<int, Node *> made_nodes;
        std::list<int> frame_allocated;
        made_nodes[node->val] = n;
        frame_allocated.push_back(node->val);
        cloneGraphPriv(n, node, made_nodes, frame_allocated);
        return n;
    }
private:
    void cloneGraphPriv(Node *n, Node *node,
                        std::unordered_map<int, Node *>& made_nodes,
                        std::list<int>& frame_allocated) {
        // Non-recursive work: make and connect all possible neighbors.
        int size = node->neighbors.size();
        for (int i = 0; i < size; i++) {
            Node *temp, *curr = node->neighbors[i];
            auto res = made_nodes.find(curr->val);  // Look up curr->val
            if (res != made_nodes.end()) {  // Only connect
                temp = res->second;
            } else {
                temp = new Node(curr->val);
                // Insert temp into made_nodes table.
                made_nodes[curr->val] = temp;
            }
            n->neighbors.push_back(temp);  // Connect.
        }

        // Recursive work: recurse to perform the same procedure with each neighbor,
        // unless a neighbor has already been allocated a stack frame.
        for (int i = 0; i < size; i++) {
            Node *curr = n->neighbors[i];
            if (std::find(frame_allocated.begin(), frame_allocated.end(), curr->val)
                == frame_allocated.end()) {
                // Allocate a new stack frame for this node and its neighbors
                frame_allocated.push_back(curr->val);
                cloneGraphPriv(curr, node->neighbors[i], made_nodes, frame_allocated);
            }
        }
    }
};
