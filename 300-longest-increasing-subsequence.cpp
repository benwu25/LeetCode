#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int *best = new int[nums.size()];
        for (int i = 0; i < nums.size(); ++i) {
            best[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i] && 1+best[j] > best[i]) {
                    best[i] = 1 + best[j];
                }
            }
        }
        int max = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (best[i] > max) {
                max = best[i];
            }
        }
        return max;
    }
};
