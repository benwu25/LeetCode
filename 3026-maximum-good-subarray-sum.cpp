#include <vector>
#include <unordered_map>
#include <limits>
using namespace std;

class Solution {
public:
    using ll = long long;

    template <typename T>
    using v = vector<T>;

    long long maximumSubarraySum(vector<int>& nums, int k) {
        v<ll> prefix(nums.size());
        prefix[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            prefix[i] = prefix[i - 1] + nums[i];
        }

        unordered_map<ll, ll> min_prefix;
        ll max_sum = numeric_limits<ll>::min();
        min_prefix[nums[0]] = 0; // prefix to left of nums[0] is zero, since prefix[i] - 0 is sum of subarray starting at 0
        bool good = false;
        for (int i = 1; i < nums.size(); ++i) {
            if (min_prefix.contains(nums[i] + k)) {
                max_sum = std::max(max_sum, prefix[i] - min_prefix[nums[i] + k]);
                good = true;
            }
            if (min_prefix.contains(nums[i] - k)) {
                max_sum = std::max(max_sum, prefix[i] - min_prefix[nums[i] - k]);
                good = true;
            }
            if (min_prefix.contains(nums[i])) {
                min_prefix[nums[i]] = std::min(min_prefix[nums[i]], prefix[i - 1]);
            } else {
                min_prefix[nums[i]] = prefix[i - 1];
            }
        }
        if (!good)
            return 0;

        return max_sum;
    }
};
