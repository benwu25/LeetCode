#include <unordered_map>
#include <limits>
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
    void max_level_sum(TreeNode *curr, int level, unordered_map<int, int> &level_count) {
        if (!curr)
            return;

        // add to level_count
        level_count[level] += curr->val;

        // dfs
        max_level_sum(curr->left, level + 1, level_count);
        max_level_sum(curr->right, level + 1, level_count);
    }

    int maxLevelSum(TreeNode* root) {
        unordered_map<int, int> level_count;
        max_level_sum(root, 1, level_count);

        int min_level = 0, max_sum = std::numeric_limits<int>::min();
        for (auto &[level, sum] : level_count) {
            if (sum > max_sum) {
                min_level = level;
                max_sum = sum;
            } else if (sum == max_sum && level < min_level)
                min_level = level;
        }

        return min_level;
    }
};

/*

    keep a map<int, int> which takes level and returns running sum at that level.

    perform a dfs tree traversal (e.g., pre-order or post-order) and build the map

    after the dfs traversal, iterate over the map to find the smallest level with maximal sum.

    this approach takes O(height) space with a map, and O(n) time (traversal takes O(n), iterating the map takes O(height)).

*/
