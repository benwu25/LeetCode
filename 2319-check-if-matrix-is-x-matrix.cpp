#include <vector>
using namespace std;

class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid.size(); ++j) {
                if (i == j && !grid[i][j]) {
                    return false;
                } else if (i == grid.size()-1-j && !grid[i][j]) {
                    return false;
                } else if (i != j && i != grid.size()-1-j && grid[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
};
