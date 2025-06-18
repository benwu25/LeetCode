#include <vector>
using namespace std;

class Solution {
public:
    int sum_digits(int val) {
        int sum = val % 10;
        int next = val/10;
        while (next > 0) {
            sum += next % 10;
            next /= 10;
        }
        return sum;
    }

    int smallestIndex(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (sum_digits(nums[i]) == i) {
                return i;
            }
        }

        return -1;
    }
};
