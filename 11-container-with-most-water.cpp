#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int water = -1, curr_water;
        while (i < j) {
            if (height[i] < height[j]) {
                curr_water = height[i] * (j-i);
                ++i;
            } else if (height[i] > height[j]) {
                curr_water = height[j] * (j-i);
                --j;
            } else {
                curr_water = height[i] * (j-i);
                ++i;
                --j;
            }
            if (water < curr_water) {
                water = curr_water;
            }
        }
        return water;
    }
};
