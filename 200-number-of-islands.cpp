#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int num_islands = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    deque<pair<int, int>> ready;
                    ready.push_back(pair<int, int>(i,j));
                    while (ready.size()) {
                        pair<int, int> curr = ready.back();
                        grid[curr.first][curr.second] = '0';
                        ready.pop_back();
                        if (curr.first+1 < grid.size() &&
                            grid[curr.first+1][curr.second] == '1') {
                            ready.push_back(pair<int, int>(curr.first+1,curr.second));
                        }
                        if (curr.second+1 < grid[0].size() &&
                            grid[curr.first][curr.second+1] == '1') {
                            ready.push_back(pair<int, int>(curr.first,curr.second+1));
                        }
                        if (curr.second-1 >= 0 &&
                            grid[curr.first][curr.second-1] == '1') {
                            ready.push_back(pair<int, int>(curr.first,curr.second-1));
                        }
                        if (curr.first-1 >= 0 &&
                            grid[curr.first-1][curr.second] == '1') {
                            ready.push_back(pair<int, int>(curr.first-1,curr.second));
                        }
                    }
                    ++num_islands;
                }
            }
        }
        return num_islands;
    }
};

/*

1 0 1 1 1
1 0 1 0 1
1 1 1 0 1

*/
