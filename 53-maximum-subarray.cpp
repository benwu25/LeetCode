#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int prev_best = nums[0];
        int best;
        int mx = prev_best;
        for (int i = 1; i < nums.size(); ++i) {
            best = std::max(nums[i]+prev_best, nums[i]);
            prev_best = best;
            mx = std::max(best, mx);
        }
        return mx;
    }
};

// best[i] gives best subarray sum ending exactly at i
// best[0] = nums[0]
// best[i] = max(nums[i]+best[i-1], nums[i])
// give max among best[i]
