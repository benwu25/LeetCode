#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if (cost.size() == 2)
            return min(cost[0], cost[1]);
        int N = cost.size();
        int *best = new int[N];
        best[N-1] = cost[N-1], best[N-2] = cost[N-2];
        for (int i = N-3; i >= 0; --i) {
            best[i] = cost[i] + min(best[i+1], best[i+2]);
        }
        int res = min(best[0], best[1]);
        delete[] best;
        return res;
    }
};

/*

best[i] gives min cost starting from step i
base cases:
best[top] = cost[top], best[top-1] = cost[top-1]
best[i] = cost[i] + min(best[i+1], best[i+2])

*/
