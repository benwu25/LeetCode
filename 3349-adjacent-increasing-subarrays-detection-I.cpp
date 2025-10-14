#include <vector>
using namespace std;

class Solution {
public:
    bool increasing(int a, int b, const vector<int> &nums) {
        for (int i = a; i < b; ++i) {
            if (nums[i] >= nums[i + 1])
                return false;
        }
        return true;
    }

    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int a = 0, b = k - 1, c = k, d = 2 * k - 1;
        while (d < nums.size()) {
            if (increasing(a, b, nums) && increasing(c, d, nums))
                return true;
            ++a; ++b; ++c; ++d;
        }
        return false;
    }
};
