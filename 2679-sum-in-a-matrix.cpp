#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        for (auto& row : nums) {
            sort(row.begin(), row.end(), [](const int& e1, const int& e2) {
                return e1 > e2;
            });
        }
        int score = 0;
        for (int i = 0; i < nums[0].size(); ++i) {
            int max = -1;
            for (int j = 0; j < nums.size(); ++j) {
                if (nums[j][i] > max)
                    max = nums[j][i];
            }
            score += max;
        }
        return score;
    }
};
