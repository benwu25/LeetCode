#include <vector>
#include <deque>
using namespace std;

class Solution {
public:

    int islandPerimeter(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j]) {
                    int perimeter = 0;
                    deque<pair<int, int>> ready;
                    ready.push_back(pair<int, int>(i, j));
                    grid[i][j] = -1;
                    while (ready.size()) {
                        pair<int, int> next = ready.back();
                        ready.pop_back();
                        if (next.first-1 >= 0 && grid[next.first-1][next.second] == 1) {
                            ready.push_back(pair<int, int>(next.first-1, next.second));
                            grid[next.first-1][next.second] = -1;
                        } else if (next.first-1 < 0 || grid[next.first-1][next.second] == 0) {
                            ++perimeter;
                        }
                        if (next.second+1 < grid[0].size() && grid[next.first][next.second+1] == 1) {
                            ready.push_back(pair<int, int>(next.first, next.second+1));
                            grid[next.first][next.second+1] = -1;
                        } else if (next.second+1 >= grid[0].size() || grid[next.first][next.second+1] == 0) {
                            ++perimeter;
                        }
                        if (next.first+1 < grid.size() && grid[next.first+1][next.second] == 1) {
                            ready.push_back(pair<int, int>(next.first+1, next.second));
                            grid[next.first+1][next.second] = -1;
                        } else if (next.first+1 >= grid.size() || grid[next.first+1][next.second] == 0) {
                            ++perimeter;
                        }
                        if (next.second-1 >= 0 && grid[next.first][next.second-1] == 1) {
                            ready.push_back(pair<int, int>(next.first, next.second-1));
                            grid[next.first][next.second-1] = -1;
                        } else if (next.second-1 < 0 || grid[next.first][next.second-1] == 0) {
                            ++perimeter;
                        }
                    }
                    return perimeter;
                }
            }
        }
        return -1;
    }
};
