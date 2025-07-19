#include <string>
using namespace std;

class Solution {
public:
    int possibleStringCount(string word) {
        int count = 1;
        for (int i = 0; i < word.size();) {
            char next = word[i];
            ++i;
            while (i < word.size() && word[i] == next) {
                ++count;
                ++i;
            }
        }
        return count;
    }
};
