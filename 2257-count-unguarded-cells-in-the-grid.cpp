#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void count_up(vector<vector<int>> &grid, int i, int j, int m, int n) {
        while (i >= 0 && (grid[i][j] == 0 || grid[i][j] == 3)) {
            grid[i][j] = 3;
            --i;
        }
    }
    void count_right(vector<vector<int>> &grid, int i, int j, int m, int n) {
        while (j < n && (grid[i][j] == 0 || grid[i][j] == 3)) {
            grid[i][j] = 3;
            ++j;
        }
    }
    void count_down(vector<vector<int>> &grid, int i, int j, int m, int n) {
        while (i < m && (grid[i][j] == 0 || grid[i][j] == 3)) {
            grid[i][j] = 3;
            ++i;
        }
    }
    void count_left(vector<vector<int>> &grid, int i, int j, int m, int n) {
        while (j >= 0 && (grid[i][j] == 0 || grid[i][j] == 3)) {
            grid[i][j] = 3;
            --j;
        }
    }

    void build(vector<vector<int>> &grid, vector<vector<int>> &guards, vector<vector<int>> &walls) {
        for (auto &guard : guards) {
            grid[guard[0]][guard[1]] = 1;
        }
        for (auto &wall : walls) {
            grid[wall[0]][wall[1]] = 2;
        }
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n));
        build(grid, guards, walls);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    count_up(grid, i - 1, j, m, n);
                    count_right(grid, i, j + 1, m, n);
                    count_down(grid, i + 1, j, m, n);
                    count_left(grid, i, j - 1, m, n);
                }
            }
        }

        int guarded = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == 3)
                    ++guarded;

        return m * n - guards.size() - walls.size() - guarded;
    }
};
