#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        deque<int> stack;
        for (int i = 0; i < nums.size(); ++i) {
            int next = nums[i];
            if (stack.size()) {
                // move this element into the stack as far as we can
                int elems_left = nums.size() - i - 1;
                while (stack.size() && stack.back() > next && elems_left >= k - stack.size()) {
                    stack.pop_back();
                }
                if (stack.size() < k) // otherwise no need
                    stack.push_back(next);
            } else
                stack.push_back(next);
        }
        return vector<int>(stack.begin(), stack.end());
    }
};
