#include <algorithm>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        int best[n+1];
        best[0] = 0;
        best[1] = 1;
        for (int i = 2; i <= n; ++i) {
            int min = i;
            for (int j = 1; j*j <= i; ++j) {
                min = std::min(1+best[i-j*j], min);
            }
            best[i] = min;
        }
        return best[n];
    }
};

// best[i] = min(1+best[i-k*k]) for k*k <= i
