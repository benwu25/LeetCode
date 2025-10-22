#include <vector>
using namespace std;

class Solution {
public:
    // find length of largest window with only 2 kinds of trees
    int totalFruit(vector<int>& fruits) {
        if (fruits.size() < 2)
            return 1;

        int max_width = 2, curr_width = 2;
        int i = 0, j = 2; // [)
        int tree1 = fruits[0], tree2 = fruits[1];
        int prev_streak_begin = (tree1 == tree2) ? 0 : 1;

        while (j < fruits.size()) {
            // if three kinds of trees, reset window
            if (fruits[j] != tree1 && fruits[j] != tree2 && tree1 != tree2) {
                // keep j, reset i, tree1, tree2, curr_width, prev_streak_begin
                i = prev_streak_begin;
                tree1 = fruits[i];
                tree2 = fruits[j];
                prev_streak_begin = j;
                ++j;
                curr_width = j - i;
            } else {
                ++curr_width;

                // if we had 1 kind of tree, update tree2
                if (tree1 == tree2)
                    tree2 = fruits[j];

                if (fruits[j] != fruits[prev_streak_begin]) {
                    // if fruits[j] is valid but breaks the streak, reset the streak
                    prev_streak_begin = j;
                }

                ++j;
            }

            max_width = std::max(max_width, curr_width);
        }

        return max_width;
    }
};
