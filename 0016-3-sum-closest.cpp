#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void find_closest_sum(vector<int> &nums, int next, int target, int i, int *closest_sum) {
        int l = i + 1, r = nums.size() - 1;
        while (l < r && r < nums.size()) {
            int three_sum = next + nums[l] + nums[r];
            if (three_sum > target) {
                --r;
            } else if (three_sum < target) {
                ++l;
            } else {
                *closest_sum = target;
                return;
            }

            if (std::abs(target - three_sum) < std::abs(target - *closest_sum))
                *closest_sum = three_sum;
        }
    }

    int threeSumClosest(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int closest_sum = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.size(); ++i) {
            int next = nums[i];
            find_closest_sum(nums, next, target, i, &closest_sum);
        }

        return closest_sum;
    }
};
