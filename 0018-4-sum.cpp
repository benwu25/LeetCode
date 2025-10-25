#include <set>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void try_quads(set<vector<int>> &quads, long long target, vector<int> &nums, int i, int j) {
        int l = j + 1, h = nums.size() - 1;
        while (l < h) {
            if (static_cast<long long>(nums[l]) + static_cast<long long>(nums[h]) == target) {
                vector<int> quad{nums[i], nums[j], nums[l], nums[h]};
                sort(quad.begin(), quad.end());
                quads.insert(quad);

                // keep going to find more quads (doesn't matter of we change l or h)
                ++l;
            } else if (static_cast<long long>(nums[l]) + static_cast<long long>(nums[h]) < target) {
                ++l;
            } else {
                --h;
            }
        }
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4)
            return {};

        sort(nums.begin(), nums.end());

        set<vector<int>> quads;
        for (int i = 0; i < nums.size() - 3; ++i) {
            for (int j = i + 1; j < nums.size() - 2; ++j) {
                try_quads(quads, static_cast<long long>(target) - static_cast<long long>(nums[i]) - static_cast<long long>(nums[j]), nums, i, j);
            }
        }

        return vector<vector<int>>(quads.begin(), quads.end());
    }
};

/*

    use two pointers, n^2, and for each set of two, look for target - nums[i] - nums[j] in the rest with another two pointers.

*/
