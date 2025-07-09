#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int lo = 0, hi = matrix.size() * matrix[0].size();
        int row_size = matrix[0].size();
        while (lo < hi) {
            int mid = (lo+hi)/2;
            int i = mid/row_size, j = mid % row_size;
            if (matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] < target) {
                lo = mid+1;
            } else {
                hi = mid;
            }
        }
        int i = lo/row_size, j = lo % row_size;
        if (i < matrix.size() && j < row_size)
            return matrix[i][j] == target;
        return false;
    }
};
