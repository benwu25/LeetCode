#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
            return a[0] < b[0];
        });

        vector<vector<int>> result;
        int curr_min = intervals[0][0], curr_max = intervals[0][1];
        int i = 1;
        while (i < intervals.size()) {
            int next1 = intervals[i][0], next2 = intervals[i][1];

            if (next1 > curr_max) {
                // add the current interval, reset curr_min, curr_max
                result.push_back({curr_min, curr_max});
                curr_min = next1;
                curr_max = next2;
            } else {
                // merge by potentially extending curr_max
                curr_max = std::max(curr_max, next2);
            }

            ++i;
        }

        result.push_back({curr_min, curr_max});

        return result;
    }
};
