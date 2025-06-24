#include <vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int N = triangle[triangle.size()-1].size();
        int *best_prev_row = new int[N];
        for (int elem = 0; elem < N; ++elem) {
            best_prev_row[elem] = triangle[triangle.size()-1][elem];
        }

        for (int row = triangle.size() - 2; row >= 0; --row) {
            for (int elem = 0; elem < triangle[row].size(); ++elem) {
                if (best_prev_row[elem] < best_prev_row[elem + 1]) {
                    best_prev_row[elem] = triangle[row][elem] + best_prev_row[elem];
                } else {
                    best_prev_row[elem] = triangle[row][elem] + best_prev_row[elem+1];
                }

            }
        }
        return best_prev_row[0];
    }
};
