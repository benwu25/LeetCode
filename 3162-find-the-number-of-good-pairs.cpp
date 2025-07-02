#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int good_pairs = 0;
        for_each(nums1.begin(), nums1.end(), [&](const int& elem1) {
            for_each(nums2.begin(), nums2.end(), [&](const int& elem2) {
                if (elem1 % (elem2 * k) == 0)
                    good_pairs++;
            });
        });
        return good_pairs;
    }
};
