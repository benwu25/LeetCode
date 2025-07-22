#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        vector<vector<int>> res(grid.size(), vector<int>(grid[0].size(), -1));
        unordered_map<int, int> l, r;
        for (int start_col = 0; start_col < grid[0].size(); ++start_col) {
            for (int i = 0, j = start_col; i < grid.size() && j < grid[0].size(); ++i, ++j) {
                r[grid[i][j]]++;
            }
            for (int i = 0, j = start_col; i < grid.size() && j < grid[0].size(); ++i, ++j) {
                if (r[grid[i][j]] == 1)
                    r.erase(grid[i][j]);
                else if (r[grid[i][j]] > 0)
                    r[grid[i][j]]--;
                int tmp = l.size()-r.size();
                res[i][j] = (tmp < 0) ? -tmp : tmp;
                l[grid[i][j]]++;
            }
            l.clear();
            r.clear();
        }
        for (int start_row = 1; start_row < grid.size(); ++start_row) {
            for (int i = start_row, j = 0; i < grid.size() && j < grid[0].size(); ++i, ++j) {
                r[grid[i][j]]++;
            }
            for (int i = start_row, j = 0; i < grid.size() && j < grid[0].size(); ++i, ++j) {
                if (r[grid[i][j]] == 1)
                    r.erase(grid[i][j]);
                else if (r[grid[i][j]] > 0)
                    r[grid[i][j]]--;
                int tmp = l.size()-r.size();
                res[i][j] = (tmp < 0) ? -tmp : tmp;
                l[grid[i][j]]++;
            }
            l.clear();
            r.clear();
        }
        return res;
    }
};
