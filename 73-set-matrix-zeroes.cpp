#include <vector>
using namespace std;

class Solution {
public:

    int next_row_with_zeroes(vector<vector<int>>& matrix, int i) {
        ++i;
        while (i < matrix.size()) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == 0) {
                    return i;
                }
            }
            ++i;
        }
        return -1;
    }

    void setZeroes(vector<vector<int>>& matrix) {
        int last_row_with_zeroes = -1;
        int first_row_with_zeroes = -1;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == 0) {
                    if (first_row_with_zeroes == -1) {
                        first_row_with_zeroes = i;
                    }
                    last_row_with_zeroes = i;
                    for (int k = 0; k < matrix[0].size(); ++k) {
                        if (matrix[i][k] != 0) {
                            matrix[i][k] = -1;
                        }
                    }
                    break;
                }
            }
        }
        if (last_row_with_zeroes == -1 || first_row_with_zeroes == -1) {
            return;
        }
        int curr_row = first_row_with_zeroes;
        while (1) {
            int next_row = next_row_with_zeroes(matrix, curr_row);
            if (next_row == -1)
                break;
            for (int j = 0; j < matrix[0].size(); ++j) {
                // encode next row
                if (matrix[curr_row][j] != -1 && matrix[next_row][j] != 0) {
                    matrix[next_row][j] = 1;
                }
                // set this row to zero
                matrix[curr_row][j] = 0;
            }
            curr_row = next_row;
        }
        for (int i = 0; i < matrix[0].size(); ++i) {
            if (matrix[last_row_with_zeroes][i] == 0 || matrix[last_row_with_zeroes][i] == 1) {
                for (int j = 0; j < matrix.size(); ++j) {
                    matrix[j][i] = 0;
                }
            }
            matrix[last_row_with_zeroes][i] = 0;
        }
    }
};
