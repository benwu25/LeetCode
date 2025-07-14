#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int mx = -1;
        for (auto& elem : piles) mx = std::max(mx, elem);
        int lo = 1, hi = mx;
        while (lo <= hi) {
            int mid = (lo+hi)/2;
            if (lo == hi) {
                return lo;
            }
            int count = 0;
            for (int i = 0; i < piles.size(); ++i) {
                int pile = piles[i];
                count += pile/mid + (pile % mid != 0);
            }
            if (lo+1 == hi && count <= h) {
                return lo;
            } else if (lo+1 == hi) {
                return hi;
            }
            if (count <= h) {
                hi = mid;
            } else {
                lo = mid+1;
            }
        }
        return -1;
    }
};
