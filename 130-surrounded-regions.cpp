#include <deque>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:

    #define UP(board, i, j) board[i-1][j]
    #define RIGHT(board, i, j) board[i][j+1]
    #define DOWN(board, i, j) board[i+1][j]
    #define LEFT(board, i, j) board[i][j-1]

    bool region_is_valid(int i,
                         int j,
                         set<pair<int, int>>& to_visit,
                         vector<vector<char>>& board) {
        bool res = true;
        deque<pair<int, int>> stack{ pair(i, j) };
        set<pair<int, int>> visited{ pair(i, j) };
        while (stack.size()) {
            pair top = stack.back();
            stack.pop_back();

            if (top.first == 0 || top.first == board.size()-1
                || top.second == 0 || top.second == board[0].size()-1)
                res = false;

            if (top.first-1 >= 0
                && !visited.count(pair(top.first-1, top.second))
                && UP(board, top.first, top.second) == 'O')
                {
                    stack.push_back(pair(top.first-1, top.second));
                    visited.insert(pair(top.first-1, top.second));
                    to_visit.insert(pair(top.first-1, top.second));
                }
            if (top.second+1 < board[0].size()
                && !visited.count(pair(top.first, top.second+1))
                && RIGHT(board, top.first, top.second) == 'O')
                {
                    stack.push_back(pair(top.first, top.second+1));
                    visited.insert(pair(top.first, top.second+1));
                    to_visit.insert(pair(top.first, top.second+1));
                }
            if (top.first+1 < board.size()
                && !visited.count(pair(top.first+1, top.second))
                && DOWN(board, top.first, top.second) == 'O')
                {
                    stack.push_back(pair(top.first+1, top.second));
                    visited.insert(pair(top.first+1, top.second));
                    to_visit.insert(pair(top.first+1, top.second));
                }
            if (top.second-1 >= 0
                && !visited.count(pair(top.first, top.second-1))
                && LEFT(board, top.first, top.second) == 'O')
                {
                    stack.push_back(pair(top.first, top.second-1));
                    visited.insert(pair(top.first, top.second-1));
                    to_visit.insert(pair(top.first, top.second-1));
                }

        }
        return res;
    }

    void solve(vector<vector<char>>& board) {
        set<pair<int, int>> visited{};
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (!visited.count(pair(i, j)) && board[i][j] == 'O') {
                    set<pair<int, int>> to_visit{ pair(i, j) };
                    bool valid = region_is_valid(i, j, to_visit, board);

                    for (auto [a, b] : to_visit) {
                        visited.insert(pair(a, b));
                        if (valid)
                            board[a][b] = 'X';
                    }
                }
            }
        }
    }
};
