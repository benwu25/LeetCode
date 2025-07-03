#include <vector>
using namespace std;

class Solution {
public:
    // [begin, end)
    int rob_exclude(int begin, int end, vector<int>& nums) {
        if (end-begin == 1) return nums[begin];
        int *best = new int[end-begin];
        best[0] = nums[begin];
        best[1] = max(nums[begin], nums[begin+1]);
        for (int i = begin+2; i < end; ++i) {
            if (best[i-1-begin] < nums[i] + best[i-2-begin]) {
                best[i-begin] = nums[i] + best[i-2-begin];
            } else {
                best[i-begin] = best[i-1-begin];
            }
        }
        int res = best[end-begin-1];
        delete[] best;
        return res;
    }
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        if (nums.size() == 3) return max(max(nums[0], nums[1]), nums[2]);
        int case1 = rob_exclude(1, nums.size()-1, nums);
        int case2 = rob_exclude(1, nums.size()-2, nums) + nums[nums.size()-1];
        int case3 = rob_exclude(2, nums.size()-1, nums) + nums[0];
        if (case1 >= case2 && case1 >= case3) return case1;
        if (case2 >= case1 && case2 >= case3) return case2;
        return case3;
    }
};
