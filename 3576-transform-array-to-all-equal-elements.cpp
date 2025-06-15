#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool countWays(vector<int>& nums, int k, int target) {
        int count = std::count(nums.begin(), nums.end(), target);
        if (count % 2 != 0) {
            return false;
        }
        int i = 0;
        int total_moves = 0;
        auto it = nums.begin();
        while (count > 0) {
            auto next_start = std::find(it, nums.end(), target);
            it = next_start + 1;
            auto next_end = std::find(it, nums.end(), target);
            it = next_end + 1;
            total_moves += (std::distance(next_start, next_end) - 1);
            total_moves += 1;
            count -= 2;
            if (total_moves > k) {
                return false;
            }
        }
        return k >= 0;
    }

    bool canMakeEqual(vector<int>& nums, int k) {
        bool validForOne = countWays(nums, k, 1);
        bool validForNegOne = countWays(nums, k, -1);
        return validForOne || validForNegOne;
    }
};
