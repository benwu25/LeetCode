#include <vector>
using namespace std;

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        vector<long long> prefixN;
        vector<long long> prefixM;
        prefixN.push_back(0);
        prefixM.push_back(0);
        for (int i = 0; i < grid.size(); ++i) prefixN[0] += grid[i][0];
        for (int i = 0; i < grid[0].size(); ++i) prefixM[0] += grid[0][i];
        for (int i = 1; i < grid[0].size(); ++i) {
            prefixN.push_back(prefixN[i - 1]);
            for (int j = 0; j < grid.size(); ++j) {
                prefixN[i] += grid[j][i];
            }
        }
        for (int i = 1; i < grid.size(); ++i) {
            prefixM.push_back(prefixM[i - 1]);
            for (int j = 0; j < grid[0].size(); ++j) {
                prefixM[i] += grid[i][j];
            }
        }
        int midN;
        int lo = 0, hi = prefixN.size();
        while (lo != hi) {
            midN = (lo + hi) / 2;
            long long L = prefixN[midN];
            long long R = prefixN[prefixN.size() - 1] - L;
            if (L == R) return true;
            if (L < R) {
                lo = midN + 1;
            } else {
                hi = midN;
            }
        }

        int midM;
        lo = 0, hi = prefixM.size();
        while (lo != hi) {
            midM = (lo + hi) / 2;
            long long L = prefixM[midM];
            long long R = prefixM[prefixM.size() - 1] - L;
            if (L == R) return true;
            if (L < R) {
                lo = midM + 1;
            } else {
                hi = midM;
            }
        }
        return false;
    }

};
