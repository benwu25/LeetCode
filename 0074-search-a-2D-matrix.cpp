#include <vector>
using namespace std;

class Solution {
public:
    bool finish(vector<vector<int>> &matrix, int curr, int target) {
        int row_len = matrix[0].size();
        int row = curr / row_len, col = curr % row_len;
        if (row < matrix.size() && col < row_len)
            return matrix[row][col] == target;

        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row_len = matrix[0].size();
        int i = 0, j = matrix.size() * row_len - 1;

        while (i < j) {
            if (i + 1 == j) {
                return finish(matrix, i, target) || finish(matrix, i + 1, target);
            }

            int mid = (i + j) / 2;
            int row = mid / row_len;
            int col = mid % row_len;
            int elem = matrix[row][col];
            if (elem == target)
                return true;
            else if (elem < target)
                i = mid + 1;
            else
                j = mid - 1;
        }

        // here, i == j. Either invalid index, or verify equal.
        return finish(matrix, i, target);
    }
};

/*

    m * n elements, list is m * n long, so start at curr := m * n / 2.
    convert to matrix coordinates: row := curr / row_len
                                   col := curr % row_len

*/
