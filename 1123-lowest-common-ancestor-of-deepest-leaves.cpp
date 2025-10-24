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
    TreeNode *lca(TreeNode *curr, int level, int max_level) {
        if (!curr)
            return nullptr;

        if (level == max_level)
            return curr;

        TreeNode *lca_left = lca(curr->left, level + 1, max_level);
        TreeNode *lca_right = lca(curr->right, level + 1, max_level);

        if (lca_left && lca_right)
            return curr;
        else if (lca_left)
            return lca_left;
        else if (lca_right)
            return lca_right;

        return nullptr;
    }

    void max_level(TreeNode *curr, int level, int *max) {
        if (!curr)
            return;

        *max = std::max(*max, level);

        max_level(curr->left, level + 1, max);
        max_level(curr->right, level + 1, max);
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int max = 0;
        max_level(root, 0, &max);

        return lca(root, 0, max);
    }
};

/*

    performa  dfs traversal of the tree (e.g., pre or post-order) while counting level to find max level

    perform a second pass (post-order traversal), checking whether a given node x must be part of the subtree.

*/
