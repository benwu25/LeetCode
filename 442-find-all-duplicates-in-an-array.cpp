#include <vector>
using namespace std;

class Solution {
public:

    struct bit {
        char b : 1;
    };

    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        struct bit *once = new struct bit[n];
        struct bit *twice = new struct bit[n];
        vector<int> result;
        for (int i = 0; i < n; ++i) {
            int num = nums[i];
            if (once[num - 1].b) {
                twice[num - 1].b = 1;
            } else {
                once[num - 1].b = 1;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (twice[i].b) {
                result.push_back(i + 1);
            }
        }
        return result;
    }
};
