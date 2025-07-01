#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int b3 = nums[0];
        int b2 = (nums[0] > nums[1]) ? nums[0] : nums[1];
        int b1;
        for (int i = 2; i < nums.size(); ++i) {
            if (b2 > nums[i] + b3) {
                b1 = b2;
            } else {
                b1 = nums[i] + b3;
            }
            b3 = b2;
            b2 = b1;
        }
        return b2;
    }
};
