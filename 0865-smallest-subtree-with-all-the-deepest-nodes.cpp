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
    // return: minimal subtree which *must* be part of the answer.
    TreeNode *deepest(TreeNode *curr, int level, int max_level) {
        if (!curr)
            return nullptr;

        // we are a deepest leaf
        if (level == max_level)
            return curr;

        TreeNode *potential_left = deepest(curr->left, level + 1, max_level);
        TreeNode *potential_right = deepest(curr->right, level + 1, max_level);

        if (potential_left && potential_right)
            return curr;
        else if (potential_left)
            return potential_left;
        else if (potential_right)
            return potential_right;

        return nullptr;
    }

    // trivial routine to calculate max depth
    void max_depth(TreeNode *curr, int level, int *max) {
        if (!curr)
            return;

        *max = std::max(*max, level);
        max_depth(curr->left, level + 1, max);
        max_depth(curr->right, level + 1, max);
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int max_level = 0;
        max_depth(root, 0, &max_level);

        return deepest(root, 0, max_level);
    }
};

/*

    options:
    compute max depth in 1 traversal, then build a set of nodes that live at that depth in a second traversal
    finally, perform a third traversal. for any node x, if x->left and x->right reach a deepest node, x must
    be part of the subtree.

    during traversal, track the largest node which *must* be part of the subtree in each branch. If both left and right
    report back a non-null subtree, then you must be part of the subtree, so report back yourself. otherwise report back
    a non-null node which must be part.
    finally, return the subtree at the root after the final traversal.

*/
