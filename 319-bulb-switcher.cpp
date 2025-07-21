#include <cmath>
using namespace std;

class Solution {
public:
    int bulbSwitch(int n) {
        if (n == 0)
            return 0;
        long long en = n;
        int on_bulbs = 1;
        float s = std::floor(std::sqrt(n));
        int sq = (int)s;
        for (long long bulb = 2; bulb <= sq + 3; ++bulb) {
            if (bulb * bulb <= en)
                ++on_bulbs;
        }
        return on_bulbs;
    }
};

// checking factors in a loop is O(n^2) which is too slow
// for the ith index, you must count how many operations overlap it
// only indices < ith index will overlap
// so basically count the factors if i(+1) that are strictly smaller than it and check if that is even or odd
// perfect squares have odd number of factors
