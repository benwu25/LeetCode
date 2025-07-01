#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        int *best = new int[amount+1];
        for (int i = 0; i < coins.size(); ++i) {
            if (coins[i] <= amount) {
                best[coins[i]] = 1;
            }
        }
        best[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            int min = INT_MAX;
            for (int j = 0; j < coins.size(); ++j) {
                if (i - coins[j] >= 0 && best[i - coins[j]] >= 0) {
                    min = (min > 1+best[i-coins[j]]) ? 1+best[i-coins[j]] : min;
                }
            }
            if (min == INT_MAX) {
                best[i] = -1;
            } else {
                best[i] = min;
            }
        }
        int res = best[amount];
        delete[] best;
        return res;
    }
};
