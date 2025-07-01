#include <vector>
#include <unordered_map>
#include <algorithm>
#include <optional>
using namespace std;

class Solution {
public:
    optional<int> binary_search_start(vector<vector<int>>& cp, int end) {
        int lo = 0, hi = cp.size();
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            int mid_start = cp[mid][0];
            if (mid_start == end) {
                return mid_start;
            } else if (mid_start < end) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        if (hi < cp.size()) {
            return cp[hi][0];
        }
        return {};
    }

    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int> result;
        unordered_map<int, int> to_index;
        for (int i = 0; i < intervals.size(); ++i) {
            to_index[intervals[i][0]] = i;
            result.push_back(-1);
        }
        sort(intervals.begin(), intervals.end(), [](auto& elem1, auto& elem2) {
            return elem1[0] < elem2[0];
        });
        for (int i = 0; i < intervals.size(); ++i) {
            int my_start = intervals[i][0];
            int end = intervals[i][1];
            optional<int> start = binary_search_start(intervals, end);
            if (!start.has_value()) {
                result[to_index[my_start]] = -1;
            } else {
                result[to_index[my_start]] = to_index[start.value()];
            }
        }
        return result;
    }

    // first solution
    vector<int> findRightIntervalOriginal(vector<vector<int>>& intervals) {
        vector<int> result;
        vector<vector<int>> cp;
        copy(intervals.begin(), intervals.end(), back_inserter(cp));
        sort(cp.begin(), cp.end(), [](auto& elem1, auto& elem2) {
            return elem1[0] < elem2[0];
        });
        unordered_map<int, int> to_index;
        for (int i = 0; i < intervals.size(); ++i) {
            to_index[intervals[i][0]] = i;
        }
        for (int i = 0; i < intervals.size(); ++i) {
            int end = intervals[i][1];
            optional<int> start = binary_search_start(cp, end);
            if (!start.has_value()) {
                result.push_back(-1);
            } else {
                result.push_back(to_index[start.value()]);
            }
        }
        return result;
    }
};
