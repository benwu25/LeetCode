#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        if (!root)
            return 0;

        int max = 0;
        int root_path = longest_path(root, root->val, &max) - 1;
        return std::max(max, root_path);
    }

    int longest_path(TreeNode *curr, int parent_val, int *max) {
        if (!curr)
            return 0;

        // get paths we can use
        int l_path = longest_path(curr->left, curr->val, max);
        int r_path = longest_path(curr->right, curr->val, max);

        // update max to use our path (no parent)
        *max = std::max(*max, l_path + r_path);

        // report to parent
        if (curr->val == parent_val) {
            // make this true for root, then subtract 1
            return 1 + std::max(l_path, r_path);
        } else {
            return 0;
        }
    }
};

/*
    perform a standard dfs tree traversal (post-order, we process x after exploring l and r paths).

    for each node x, try to form paths with x->left and x->right using x->val.
    1. if x->val matches parent val, report the max path you find to your parent (merging with their path).
    2. also update overall max path length using the independent two-way path which goes through x (add the x->l and x->r paths)
        (parent node does not participate in this path).

    if x value does not match parent value, return 0 as the reported path, and still update max with your path (2).

*/
