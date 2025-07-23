#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> earliest;
        int max = 0;
        int count = 0;
        earliest[0] = -1;
        for (int i = 0; i < nums.size(); ++i) {
            switch (nums[i]) {
                case 0:
                    --count;
                    break;
                case 1:
                    ++count;
                    break;
            }
            if (earliest.count(count)) {
                max = std::max(i-earliest[count], max);
            } else {
                earliest[count] = i;
            }
        }
        return max;
    }
};

// 1 1 0 0
// (]
// earliest is exclusive bound, i is inclusive bound
