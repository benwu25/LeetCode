#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int median = nums[nums.size() / 2];
        int count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            count += abs(nums[i] - median);
        }
        return count;
    }
};
