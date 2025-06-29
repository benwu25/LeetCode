#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 0;
        int base = nums[0];
        for (int i = nums.size() - 1; i >= 1; --i) {
            count += nums[i] - base;
        }
        return count;
    }
};
