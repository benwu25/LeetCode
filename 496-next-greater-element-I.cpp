#include <vector>
#include <unordered_map>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> index_for_nums1;
        vector<int> result;
        for (int i = 0; i < nums1.size(); ++i) {
            index_for_nums1[nums1[i]] = i;
            result.push_back(-1);
        }
        deque<int> monotonic_stack;
        for (int i = 0; i < nums2.size(); ++i) {
            while (monotonic_stack.size() && monotonic_stack.back() < nums2[i]) {
                result[index_for_nums1[monotonic_stack.back()]] = nums2[i];
                monotonic_stack.pop_back();
            }
            if (index_for_nums1.count(nums2[i]))
                monotonic_stack.push_back(nums2[i]);
        }
        return result;
    }
};
