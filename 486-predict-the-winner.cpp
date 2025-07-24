#include <vector>
using namespace std;

class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        if (nums.size() == 1 || nums.size() == 2)
            return true;
        int best1[nums.size()][nums.size()];
        int best2[nums.size()][nums.size()];
        int sum[nums.size()][nums.size()];

        for (int i = 0; i < nums.size(); ++i) {
            best1[i][i] = nums[i];
            best2[i][i] = nums[i];
            sum[i][i] = nums[i];
        }
        for (int i = 0, j = 1; j < nums.size(); ++i, ++j) {
            best1[i][j] = max(nums[i], nums[j]);
            best2[i][j] = max(nums[i], nums[j]);
            sum[i][j] = nums[i] + nums[j];
        }
        bool one_turn = ((nums.size()-3) % 2 == 0) ? true : false;
        for (int diff = 2; diff < nums.size(); ++diff) {
            for (int i = 0, j = diff; j < nums.size(); ++i, ++j) {
                if (one_turn) {
                    best1[i][j] = max(
                        nums[i]+sum[i+1][j]-best2[i+1][j],
                        nums[j]+sum[i][j-1]-best2[i][j-1]
                    );
                    // <0?
                    sum[i][j] = nums[i]+nums[j]+sum[i+1][j-1];
                } else {
                    best2[i][j] = max(
                        nums[i]+sum[i+1][j]-best1[i+1][j],
                        nums[j]+sum[i][j-1]-best1[i][j-1]
                    );
                    // <0?
                    sum[i][j] = nums[i]+nums[j]+sum[i+1][j-1];
                }
            }
            one_turn = !one_turn;
        }
        int best_for_alice = best1[0][nums.size()-1];
        return best_for_alice >= sum[0][nums.size()-1]-best_for_alice;
    }
};
