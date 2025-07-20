#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxOnes(vector<int>& nums) {
        int i = 0, j = 0;
        int count = 0, mx = -1;
        while (j < nums.size()) {
            if (nums[i] == 0) {
                ++i;
                ++j;
            } else if (nums[j] == 0) {
                i = j;
                mx = std::max(count, mx);
                count = 0;
            } else {
                ++j;
                ++count;
            }
            mx = std::max(count, mx);
        }
        return mx;
    }

    int longestOnes(vector<int>& nums, int k) {
        if (k == 0) {
            return maxOnes(nums);
        }
        int i = 0, j = 0;
        deque<int> zeros;
        int count = 0, mx = 0;
        while (j < nums.size()) {
            if (nums[j] == 1) {
                ++j;
                ++count;
            } else if (zeros.size() == k) {
                count -= (zeros.front()-i+1);
                i = zeros.front()+1;
                zeros.pop_front();
                zeros.push_back(j);
                ++count;
                ++j;
            } else {
                zeros.push_back(j);
                ++count;
                ++j;
            }
            mx = std::max(count, mx);
        }
        return mx;
    }
};

// you will only want to flip consecutive zeros (i.e., you won't skip a zero and flip someone to its left and right)
// so just slide and flip consecutive zeros, at most k though
