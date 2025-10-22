#include <vector>
#include <deque>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root)
            return {};

        vector<vector<int>> res;
        deque<TreeNode *> nodes{nullptr, root};
        bool once = false;
        while (nodes.size()) {
            TreeNode *next = nodes.front();
            nodes.pop_front();

            if (!next) {
                if (once)
                    break;

                // new level
                res.push_back({});
                nodes.push_back(nullptr);
                once = true;
            } else {
                once = false;

                res.back().push_back(next->val);

                if (next->left)
                    nodes.push_back(next->left);
                if (next->right)
                    nodes.push_back(next->right);
            }
        }

        res.erase(res.end() - 1);

        return res;
    }
};
