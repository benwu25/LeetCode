#include <vector>
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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res{};
        vector<int> unused{};
        if (!root)
            return res;
        if (!root->left && !root->right) {
            if (root->val != targetSum)
                return res;
            res.push_back({root->val});
            return res;
        }
        if (!root->right) {
            pathSum(res, unused, root->val, root->left, targetSum);
            for (auto& v : res)
                v.insert(v.begin(), root->val);
            return res;
        }
        if (!root->left) {
            pathSum(res, unused, root->val, root->right, targetSum);
            for (auto& v : res)
                v.insert(v.begin(), root->val);
            return res;
        }
        pathSum(res, unused, root->val, root->left, targetSum);
        pathSum(res, unused, root->val, root->right, targetSum);
        for (auto& v : res)
            v.insert(v.begin(), root->val);
        return res;
    }

    // leaf pushes vector<int> to res and pushes itself to front of that vector
    // if a child is valid, it will give a list of indices in res you should
    // push yourself to the front of
    bool pathSum(vector<vector<int>>& res, vector<int>& indices, int sum, TreeNode *curr, int targetSum) {
        if (!curr->left && !curr->right) {
            if (curr->val + sum != targetSum)
                return false;
            res.push_back(vector<int>{});
            res.back().push_back(curr->val);
            indices.push_back(res.size()-1);
            return true;
        }
        if (!curr->right) {
            vector<int> needs_us{};
            if (!pathSum(res, needs_us, sum+curr->val, curr->left, targetSum))
                return false;
            for (auto& idx : needs_us) {
                res[idx].insert(res[idx].begin(), curr->val);
                indices.push_back(idx);
            }
            return true;
        }
        if (!curr->left) {
            vector<int> needs_us{};
            if (!pathSum(res, needs_us, sum+curr->val, curr->right, targetSum))
                return false;
            for (auto& idx : needs_us) {
                res[idx].insert(res[idx].begin(), curr->val);
                indices.push_back(idx);
            }
            return true;
        }
        vector<int> l_need{}, r_need{};
        bool ret = false;
        if (pathSum(res, l_need, sum+curr->val, curr->left, targetSum)) {
            for (auto& idx: l_need) {
                res[idx].insert(res[idx].begin(), curr->val);
                indices.push_back(idx);
            }
            ret = true;
        }
        if (pathSum(res, r_need, sum+curr->val, curr->right, targetSum)) {
            for (auto& idx : r_need) {
                res[idx].insert(res[idx].begin(), curr->val);
                indices.push_back(idx);
            }
            ret = true;
        }
        return ret;
    }
};
