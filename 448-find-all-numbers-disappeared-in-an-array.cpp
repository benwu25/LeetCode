#include<vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            int tmp = nums[abs(nums[i]) - 1];
            if (tmp > 0) {
                nums[abs(nums[i]) - 1] = -tmp;
            }
        }
        vector<int> result;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                result.push_back(i + 1);
            }
        }
        return result;
    }
};
