#include <string>
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
    void find_depth(TreeNode *curr, int level, int *max) {
        if (!curr)
            return;

        *max = std::max(level, *max);
        find_depth(curr->left, level + 1, max);
        find_depth(curr->right, level + 1, max);
    }

    bool smallest_from_leaf(TreeNode *curr, string curr_str, string *min) {
        if (!curr)
            return true;

        bool l = smallest_from_leaf(curr->left, curr_str + (char)('a' + curr->val), min);
        bool r = smallest_from_leaf(curr->right, curr_str + (char)('a' + curr->val), min);
        if (l && r) {
            curr_str += (char)('a' + (char)curr->val);
            std::reverse(curr_str.begin(), curr_str.end());
            *min = std::min(*min, curr_str);
        }
        return false;
    }

    string smallestFromLeaf(TreeNode* root) {
        int level = 1;
        find_depth(root, 1, &level);

        string min;
        for (int i = 1; i <= level; ++i) {
            min += "z";
        }

        smallest_from_leaf(root, "", &min);
        return min;
    }
};
