#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> result, filled;
        for_each(nums.begin(), nums.end(), [&](const int& elem) {
            result.push_back(-1);
            filled.push_back(0);
        });
        deque<int> index_stack;
        int filled_count = 0;
        for (int i = 0; i < 2 * nums.size(); ++i) {
            while (index_stack.size() && nums[index_stack.back()] < nums[i % nums.size()]) {
                int elem_index = index_stack.back();
                if (!filled[elem_index]) {
                    filled[elem_index] = 1;
                    result[elem_index] = nums[i % nums.size()];
                    ++filled_count;
                }
                index_stack.pop_back();
            }
            if (!filled[i % nums.size()]) {
                index_stack.push_back(i % nums.size());
            }
            if (filled_count == nums.size())
                break;
        }
        return result;
    }
};
