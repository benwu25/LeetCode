#include <vector>
using namespace std;

bool validPartition(vector<int>& nums) {
        if (nums.size() == 2)
            return nums[0] == nums[1];

        int best[nums.size()];
        best[0] = 0;
        best[1] = nums[0] == nums[1];
        best[2] =
            nums[0] + 1 == nums[1] && nums[1] + 1 == nums[2]
            || nums[0] == nums[1] && nums[1] == nums[2];

        for (int i = 3; i < nums.size(); ++i) {

            // three equal elements
            if (nums[i - 2] == nums[i - 1] && nums[i - 1] == nums[i] && best[i - 3])
                best[i] = 1;
            else if (nums[i - 2] + 1 == nums[i - 1] && nums[i - 1] + 1 == nums[i] && best[i - 3])
                best[i] = 1;
            else if (best[i - 2] && nums[i - 1] == nums[i])
                best[i] = 1;
            else
                best[i] = 0;
        }

        return static_cast<bool>(best[nums.size() - 1]);
    }
};

/*
    best[i] is true if the subarray nums[0:i] has a valid partition.

    best[0] = false
    best[1] = (check nums[0] and nums[1])
    best[2] = (check 3 consecutive)

    consider [nums[i - 2], nums[i - 1], nums[i]]
    check case 1, 2, and 3, and best[i - 3]
    best[i] = true
*/
