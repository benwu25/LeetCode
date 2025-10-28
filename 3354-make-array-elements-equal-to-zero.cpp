#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    bool simulate(vector<int> nums, int curr, bool left) {
        while (0 <= curr && curr < nums.size()) {
            if (nums[curr] == 0 && left) {
                --curr;
            } else if (nums[curr] == 0 && !left) {
                ++curr;
            } else {
                --nums[curr];
                left = !left;
                if (left)
                    --curr;
                else
                    ++curr;
            }
        }
        for (auto &elem : nums)
            if (elem != 0)
                return false;
        return true;
    }

    int countValidSelections(vector<int>& nums) {
        set<int> zeros;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0)
                zeros.insert(i);
        }

        int valid = 0;
        for (auto &selection_start : zeros) {
            if (simulate(nums, selection_start, true))
                ++valid;
            if (simulate(nums, selection_start, false))
                ++valid;
        }
        return valid;
    }
};

/*

    find all indices where nums[i] == 0
    for each index,

*/
