#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](auto& elem1, auto& elem2) {
            return elem1[0] < elem2[0];
        });
        int min = points[0][0], max = points[0][1];
        int count = 0;
        for (int i = 1; i < points.size(); ++i) {
            if (points[i][0] > max || points[i][1] < min) {
                ++count;
                min = points[i][0];
                max = points[i][1];
                continue;
            }
            if (points[i][0] >= min) {
                min = points[i][0];
            }
            if (points[i][1] <= max) {
                max = points[i][1];
            }
        }
        return count + 1;
    }
};
