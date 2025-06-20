#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int mid, lo = 0, hi = nums.size();
        while (lo + 1 != hi) {
            mid = (lo + hi) / 2;
            if (nums[lo] < nums[mid] && nums[mid] < nums[hi - 1]) {
                return nums[lo];
            } else if (nums[mid] < nums[hi - 1] && nums[hi - 1] < nums[lo]) {
                hi = mid + 1;
            } else if (nums[hi - 1] < nums[lo] && nums[lo] < nums[mid]) {
                lo = mid + 1;
            } else if (nums[lo] < nums[hi - 1]) {
                hi = lo + 1;
            } else if (nums[lo] > nums[hi - 1]) {
                lo = hi - 1;
            }
        }
        return nums[lo];
    }
};
