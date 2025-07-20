#include <string>
#include <unordered_set>
#include <deque>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSeq(string& s, unordered_set<char>& search) {
        int abs_max = 0;
        for (char c : search) {
            int i = 0, j = 0;
            int count = 0, max = 0;
            while (j < s.size()) {
                if (s[i] != c) {
                    ++i;
                    ++j;
                } else if (s[j] != c) {
                    i = j;
                    max = std::max(count, max);
                    count = 0;
                } else {
                    ++count;
                    ++j;
                }
                max = std::max(count, max);
            }
            abs_max = std::max(max, abs_max);
        }
        return abs_max;
    }

    int characterReplacement(string s, int k) {
        unordered_set<char> search;
        for (auto c : s) {
            search.insert(c);
        }
        if (k == 0) {
            return maxSeq(s, search);
        }
        int abs_max = 0;
        for (char c : search) {
            int i = 0, j = 0;
            int count = 0, max = 0;
            deque<int> flips;
            while (j < s.size()) {
                if (s[j] == c) {
                    ++j;
                    ++count;
                } else if (flips.size() == k) {
                    count -= (flips.front()-i+1);
                    i = flips.front()+1;
                    flips.pop_front();
                    flips.push_back(j);
                    ++count;
                    ++j;
                } else {
                    flips.push_back(j);
                    ++count;
                    ++j;
                }
                max = std::max(count, max);
            }
            abs_max = std::max(max, abs_max);
        }
        return abs_max;
    }
};

// same as 1004, just run routine for each character [A-Z], treating all other characters as "0" and sliding along flipping them
