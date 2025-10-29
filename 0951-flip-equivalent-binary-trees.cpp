#include <algorithm>
using namespace std;

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
    // curr1 && curr2 && curr1->val == curr2->val
    bool checkEqual(TreeNode *curr1, TreeNode *curr2) {
        if (curr1->left && curr1->right && curr2->left && curr2->right) {

            if (curr1->left->val != curr2->left->val) {
                swap(curr1->left, curr1->right);
                if (curr1->left->val != curr2->left->val || curr1->right->val != curr2->right->val) {
                    return false;
                }

            } else if (curr1->right->val != curr2->right->val) {
                return false;
            }

            return checkEqual(curr1->left, curr2->left) && checkEqual(curr1->right, curr2->right);

        } else if (curr1->left && !curr1->right && curr2->left && !curr2->right) {

            if (curr1->left->val != curr2->left->val) {
                return false;
            }

            return checkEqual(curr1->left, curr2->left);

        } else if (curr1->left && !curr1->right && !curr2->left && curr2->right) {

            if (curr1->left->val != curr2->right->val) {
                return false;
            }

            swap(curr1->left, curr1->right);
            return checkEqual(curr1->right, curr2->right);

        } else if (!curr1->left && curr1->right && curr2->left && !curr2->right) {

            if (curr1->right->val != curr2->left->val) {
                return false;
            }

            swap(curr1->right, curr1->left);
            return checkEqual(curr1->left, curr2->left);

        } else if (!curr1->left && curr1->right && !curr2->left && curr2->right) {

            if (curr1->right->val != curr2->right->val) {
                return false;
            }

            return checkEqual(curr1->right, curr2->right);
        } else if (!curr1->left && !curr1->right && !curr2->left && !curr2->right) {
            return true;
        }
        return false;
    }

    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if (!root1 && root2 || root1 && !root2) {
            return false;
        } else if (!root1 && !root2) {
            return true;
        } else if (root1->val != root2->val) {
            return false;
        }

        return checkEqual(root1, root2);
    }
};
