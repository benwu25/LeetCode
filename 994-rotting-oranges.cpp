#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        deque<pair<int, int>> ready;
        bool has_fresh;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 2)
                    ready.push_back(pair(i, j));
                else if (grid[i][j] == 1)
                    has_fresh = true;
            }
        }
        if (!has_fresh)
            return 0;
        ready.push_back(pair(-1, -1));
        int steps = 0;
        while (ready.size()) {
            auto next = ready.front();
            ready.pop_front();
            if (next.first == -1 && next.second == -1) {
                if (ready.size()) {
                    ++steps;
                    ready.push_back(pair(-1, -1));
                    continue;
                }
                break;
            }
            if (next.first-1 >= 0 && grid[next.first-1][next.second] == 1) {
                grid[next.first-1][next.second] = 2;
                ready.push_back(pair(next.first-1, next.second));
            }
            if (next.first+1 < grid.size()
            && grid[next.first+1][next.second] == 1) {
                grid[next.first+1][next.second] = 2;
                ready.push_back(pair(next.first+1, next.second));
            }
            if (next.second-1 >= 0 && grid[next.first][next.second-1] == 1) {
                grid[next.first][next.second-1] = 2;
                ready.push_back(pair(next.first, next.second-1));
            }
            if (next.second+1 < grid[0].size()
            && grid[next.first][next.second+1] == 1) {
                grid[next.first][next.second+1] = 2;
                ready.push_back(pair(next.first, next.second+1));
            }
        }
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1)
                    return -1;
            }
        }
        return steps;
    }
};
