#include <climits>

class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        if (n <= k && m <= k) {
            return 0;
        }
        long long big_log = (n <= k) ? static_cast<long long>(m) : static_cast<long long>(n);
        long long min = LLONG_MAX;
        for (long long i = big_log - k; i <= k; ++i) {
            if (big_log * i - i * i < min) min = big_log * i - i * i;
        }
        return min;
    }
};
