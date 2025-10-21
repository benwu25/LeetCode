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
    int widthOfBinaryTree(TreeNode* root) {
        unordered_map<int, unsigned long long> levl_to_mindist, levl_to_maxdist;
        traverse(root, 0, 0, levl_to_mindist, levl_to_maxdist);

        unsigned long long max_width = 0;
        for (auto &[level, smallest_dist] : levl_to_mindist) {
            unsigned long long largest_dist = levl_to_maxdist[level];
            max_width = std::max(static_cast<unsigned long long>(max_width), largest_dist - smallest_dist + 1);
        }

        return static_cast<int>(max_width);
    }

    void update_maps(int level,
                     unsigned long long idx,
                     unordered_map<int, unsigned long long> &levl_to_mindist,
                     unordered_map<int, unsigned long long> &levl_to_maxdist)
    {
        if (levl_to_mindist.contains(level))
            levl_to_mindist[level] = std::min(levl_to_mindist[level], idx);
        else
            levl_to_mindist[level] = idx;

        if (levl_to_maxdist.contains(level))
            levl_to_maxdist[level] = std::max(levl_to_maxdist[level], idx);
        else
            levl_to_maxdist[level] = idx;
    }

    void traverse(TreeNode *curr,
                  int level,
                  unsigned long long idx,
                  unordered_map<int, unsigned long long> &levl_to_mindist,
                  unordered_map<int, unsigned long long> &levl_to_maxdist)
    {
        if (!curr)
            return;

        update_maps(level, idx, levl_to_mindist, levl_to_maxdist);
        traverse(curr->left, level + 1, 2*idx + 1, levl_to_mindist, levl_to_maxdist);
        traverse(curr->right, level + 1, 2*idx + 2, levl_to_mindist, levl_to_maxdist);
    }
};
