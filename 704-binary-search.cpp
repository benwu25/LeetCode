#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size(), mid;
        while (lo+1 < hi) {
            mid = (lo+hi)/2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                lo = mid+1;
            } else {
                hi = mid;
            }
        }
        if (nums[lo] == target)
            return lo;
        return -1;
    }
};
