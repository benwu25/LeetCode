#include <vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int lo = 0, hi = nums.size();
        while (hi-lo >= 3) {
            int mid = (lo + hi) / 2;
            int val = nums[mid], left = nums[mid-1], right = nums[mid+1];
            if (left != val && right != val) {
                return val;
            } else if (left == val && (mid-lo+1) % 2 == 0) {
                lo = mid+1;
            } else if (left == val && (mid-lo+1) % 2 != 0) {
                hi = mid-1;
            } else if (right == val && (hi-mid) % 2 == 0) {
                hi = mid;
            } else if (right == val && (hi-mid) % 2 != 0) {
                lo = mid+2;
            }

        }
        return nums[lo];
    }
};
