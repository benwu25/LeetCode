class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int max = 0;
        int is_valid[matrix.size()][matrix[0].size()];
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == '1') {
                    max = 1;
                    is_valid[i][j] = 1;
                } else {
                    is_valid[i][j] = 0;
                }
            }
        }
        int mn = (matrix.size() < matrix[0].size()) ? matrix.size() : matrix[0].size();
        for (int size = 2; size <= mn; ++size) {
            for (int i = 0; i+size <= matrix.size(); ++i) {
                for (int j = 0; j+size <= matrix[0].size(); ++j) {
                    if (is_valid[i][j] && is_valid[i+1][j]
                    && is_valid[i][j+1] && is_valid[i+1][j+1]) {
                        is_valid[i][j] = 1;
                        max = size;
                    } else
                        is_valid[i][j] = 0;
                }
            }
        }
        return max * max;
    }
};

// optimize: need to go bottom up and build on top of one of the corners, like a square prefix sum
