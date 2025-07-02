#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> result;
        bool go_up = true;
        int i = 0, j = 0;
        int iterations = mat.size() * mat[0].size();
        for (int count = 0; count < iterations; ++count) {
            result.push_back(mat[i][j]);
            if (go_up && i == 0 && j < mat[0].size()-1) {
                // go right
                ++j;
                go_up = !go_up;
            } else if (go_up && j == mat[0].size()-1) {
                // go down
                ++i;
                go_up = !go_up;
            } else if (!go_up && j == 0 && i < mat.size()-1) {
                // go down
                ++i;
                go_up = !go_up;
            } else if (!go_up && i == mat.size()-1) {
                // go right
                ++j;
                go_up = !go_up;
            } else if (go_up) {
                // go up and right
                --i;
                ++j;
            } else if (!go_up) {
                // go down and left
                ++i;
                --j;
            }
        }
        return result;
    }
};
