#include <vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int **best = new int*[triangle.size()];
        for (int i = 0; i < triangle.size(); ++i) {
            best[i] = new int[triangle[triangle.size() - 1].size()];
        }

        for (int elem = 0; elem < triangle[triangle.size() - 1].size(); ++elem) {
            best[triangle.size() - 1][elem] = triangle[triangle.size() - 1][elem];
        }

        for (int row = triangle.size() - 2; row >= 0; --row) {
            for (int elem = 0; elem < triangle[row].size(); ++elem) {
                int nxt_rw = row + 1;
                if (best[nxt_rw][elem] < best[nxt_rw][elem+1]) {
                    best[row][elem] = triangle[row][elem] + best[nxt_rw][elem];
                } else {
                    best[row][elem] = triangle[row][elem] + best[nxt_rw][elem+1];
                }
            }
        }
        return best[0][0];
    }
};
