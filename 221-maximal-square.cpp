#include <vector>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int max = 0;
        int best[matrix.size()][matrix[0].size()];
        for (int j = 0; j < matrix[0].size(); ++j) {
            if (matrix[0][j] == '1')
                best[0][j] = max = 1;
            else
                best[0][j] = 0;
        }
        for (int i = 0; i < matrix.size(); ++i) {
            if (matrix[i][0] == '1')
                best[i][0] = max = 1;
            else
                best[i][0] = 0;
        }
        for (int i = 1; i < matrix.size(); ++i) {
            for (int j = 1; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == '0') {
                    best[i][j] = 0;
                } else if (best[i][j-1] > 0 && best[i-1][j] > 0 && best[i-1][j-1] > 0) {
                    best[i][j] = 1+std::min(best[i][j-1], std::min(best[i-1][j], best[i-1][j-1]));
                } else {
                    best[i][j] = 1;
                }
                max = std::max(max, best[i][j]);
            }
        }
        return max * max;
    }
};

/*

let best[i][j] give length of longest square with bottom right corner at i,j
best[i][j] = 0 if matrix[i][j] == 0
otherwise if best[i][j-1] > 0 and best[i-1][j] > 0 and best[i-1][j-1] > 0, best[i][j] = 1+min
otherwise best[i][j] = 1

*/
