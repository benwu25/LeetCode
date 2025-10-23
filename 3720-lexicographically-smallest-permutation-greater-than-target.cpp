#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        // find the break point in s
        // match as much as you can, but remember the last idx in s where you could beat target
        // either match everything until you can't, then end of match is the last place where you beat target
        // otherwise if matching fails, go back to the last place where you could beat target
        unordered_map<char, int> count, save_count;
        for (auto &c : s) {
            count[c]++;
            save_count[c]++;
        }

        int break_point = 0;
        char breaking_char = '\0';
        for (int i = 0; i < target.size(); ++i) {
            char next = target[i];

            // find the minimum character left we could use to beat target at idx i and set break_point for later
            // update save_count to match count rather than save_count at a previous break_point
            for (char better = next + 1; better <= 'z'; ++better) {
                if (count[better] > 0) {
                    break_point = i;
                    breaking_char = better;
                    save_count = count;
                    break;
                }
            }

            // greedily use next at spot i
            if (count[next] > 0) {
                count[next]--;
            } else {
                // we can't match any more, break at breaking_point

                // if we never found any place to beat target, we can't beat target
                if (breaking_char == '\0')
                    return "";

                // match up to break_point
                string res("");
                for (int j = 0; j < break_point; ++j)
                    res += target[j];

                // add the breaking_char we selected and decrement its count in save_count
                res += breaking_char;
                save_count[breaking_char]--;

                // bundle up the remaining characters at the end and sort lexicographically smallest
                string rest("");
                for (auto &[character, cnt] : save_count) {
                    for (int j = 0; j < cnt; ++j)
                        rest += character;
                }
                std::sort(rest.begin(), rest.end());

                return res + rest;
            }
        }

        if (breaking_char != '\0') {
            string res("");
            for (int j = 0; j < break_point; ++j)
                res += target[j];

            res += breaking_char;
            save_count[breaking_char]--;

            string rest("");
            for (auto &[character, cnt] : save_count) {
                for (int j = 0; j < cnt; ++j)
                    rest += character;
            }
            std::sort(rest.begin(), rest.end());

            return res + rest;
        }

        return "";
    }
};
