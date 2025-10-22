#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> best(nums.size());
        int longest = 1;
        for (int i = 0; i < nums.size(); ++i) {
            best[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j])
                    best[i] = std::max(best[i], 1 + best[j]);
            }

            longest = std::max(longest, best[i]);
        }

        return longest;
    }
};
