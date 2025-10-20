#include <vector>
#include <unordered_map>
using namespace std;

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
    vector<int> largestValues(TreeNode* root) {
        unordered_map<int, int> best;
        int max_depth_idx = -1;
        largest_values(root, 0, best, &max_depth_idx);

        if (max_depth_idx == -1)
            return {};

        vector<int> result(max_depth_idx + 1, 0);
        for (auto &[levl, max] : best) {
            result[levl] = max;
        }
        return result;
    }

    void largest_values(TreeNode *curr, int level, unordered_map<int, int> &best, int *p) {
        if (!curr)
            return;

        // level is valid level
        *p = std::max(*p, level);

        if (best.contains(level))
            best[level] = std::max(best[level], curr->val);
        else
            best[level] = curr->val;
        largest_values(curr->left, level + 1, best, p);
        largest_values(curr->right, level + 1, best, p);
    }
};
