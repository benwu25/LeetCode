#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.size() == 0) return vector<string>();
        vector<string> result;
        int begin = nums[0], end = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (end+1 == nums[i]) {
                end = nums[i];
            } else if (begin != end) {
                result.push_back(to_string(begin) + "->" + to_string(end));
                begin = nums[i];
                end = nums[i];
            } else {
                result.push_back(to_string(begin));
                begin = nums[i];
                end = nums[i];
            }
        }
        if (begin == end) {
            result.push_back(to_string(begin));
        } else {
            result.push_back(to_string(begin) + "->" + to_string(end));
        }
        return result;
    }
};
