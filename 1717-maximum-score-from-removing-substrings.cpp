#include <string>
#include <deque>
using namespace std;

class Solution {
public:
    int update_score_with(string& curr, string& next, char first, char second, int add) {
        if (!curr.size())
            return 0;
        int score = 0;
        deque<char> stack;
        for (int i = 0; i < curr.size(); ++i) {
            if (!stack.size()) {
                stack.push_back(curr[i]);
                continue;
            }
            char p = stack.back();
            if (p != first) {
                stack.push_back(curr[i]);
                continue;
            }
            if (curr[i] != second) {
                stack.push_back(curr[i]);
                continue;
            }
            stack.pop_back();
            score += add;
        }
        for (auto c : stack)
            next += c;
        return score;
    }
    int maximumGain(string s, int x, int y) {
        int score = 0;
        string next(""), unused("");
        if (x >= y) {
            score += update_score_with(s, next, 'a', 'b', x);
            score += update_score_with(next, unused, 'b', 'a', y);
        } else {
            score += update_score_with(s, next, 'b', 'a', y);
            score += update_score_with(next, unused, 'a', 'b', x);
        }
        return score;
    }
};
