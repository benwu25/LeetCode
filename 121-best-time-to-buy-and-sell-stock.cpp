#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 1)
            return 0;
        int l = 0, r = 1;
        int best_dif = 0;
        while (r < prices.size()) {
            if (prices[r] - prices[l] > best_dif) {
                best_dif = prices[r] - prices[l];
                ++r;
            } else if (prices[r] >= prices[l]) {
                ++r;
            } else if (prices[r] < prices[l]) {
                l = r;
                ++r;
            }
        }
        return best_dif;
    }
};
