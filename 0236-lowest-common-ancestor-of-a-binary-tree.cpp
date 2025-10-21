#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *lca = nullptr;
        lowest_common(root, p, q, &lca);
        return lca;
    }

    bool lowest_common(TreeNode *curr, TreeNode *p, TreeNode *q, TreeNode **lca) {
        if (!curr || *lca)
            return false;

        bool lresult = lowest_common(curr->left, p, q, lca);
        bool rresult = lowest_common(curr->right, p, q, lca);

        if (*lca)
            return false;

        if (lresult && rresult) {
            // success
            *lca = curr;
            return true;
        } else if ((lresult || rresult) && (p == curr || q == curr)) {
            // success
            *lca = curr;
            return true;
        } else if (p == curr || q == curr) {
            return true;
        }

        // propagate the result
        return lresult || rresult;
    }
};
