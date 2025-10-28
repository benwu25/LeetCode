#include <iostream>

class Solution {
public:
    int minOperations(int k) {
        if (k == 1)
            return 0;

        int min = k;
        for (int i = 1; i <= k; ++i) {
            min = std::min(min, i - 1 + (k-i)/i + ((k-i)%i != 0));
        }
        return min;
    }
};
