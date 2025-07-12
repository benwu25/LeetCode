#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long lo = 0, hi = 10 * 10 * 10 * 10 * 10 * 10 * 10 * 10 * 10;
        vector<long long> cp;
        copy(nums.begin(), nums.end(), back_inserter(cp));
        bool one = false;
        while (lo < hi) {
            int mid = (lo+hi)/2;
            long long max = nums[0];
            cp[cp.size()-1] = nums[nums.size()-1];
            for (int i = cp.size()-2; i >= 0; --i) {
                if (cp[i+1] > mid) {
                    cp[i] = nums[i] + cp[i+1]-mid;
                    cp[i+1] = mid;
                } else {
                    cp[i] = nums[i];
                }
                max = std::max(cp[i+1], max);
            }
            max = std::max(max, cp[0]);
            if (max > mid) {
                lo = mid+1;
                one = true;
            } else if (max <= mid) {
                hi = mid;
                one = false;
            }
        }
        if (!one)
            return lo;
        return hi;
    }
};
