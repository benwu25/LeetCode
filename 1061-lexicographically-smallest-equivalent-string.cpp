#include <vector>
#include <set>
#include <string>
using namespace std;

class Solution {
public:
    struct EquivalentChars {
        char min;
        set<char> equivalent;
    };

    int search_sets(vector<EquivalentChars>& sets, char c) {
        for (int i = 0; i < sets.size(); ++i) {
            if (c == sets[i].min || sets[i].equivalent.count(c)) {
                return i;
            }
        }
        return -1;
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<EquivalentChars> sets;
        for (int i = 0; i < s1.length(); ++i) {
            int c1_set_idx = search_sets(sets, s1[i]);
            int c2_set_idx = search_sets(sets, s2[i]);
            if (c1_set_idx == -1 && c2_set_idx == -1) {
                struct EquivalentChars ec;
                ec.min = (s1[i] < s2[i]) ? s1[i] : s2[i];
                ec.equivalent.insert(s1[i]);
                ec.equivalent.insert(s2[i]);
                sets.push_back(ec);
            } else if (c1_set_idx == -1 && c2_set_idx != -1) {
                sets[c2_set_idx].equivalent.insert(s1[i]);
                if (s1[i] < sets[c2_set_idx].min) {
                    sets[c2_set_idx].min = s1[i];
                }
            } else if (c1_set_idx != -1 && c2_set_idx == -1) {
                sets[c1_set_idx].equivalent.insert(s2[i]);
                if (s2[i] < sets[c1_set_idx].min) {
                    sets[c1_set_idx].min = s2[i];
                }
            } else if (c1_set_idx != -1 && (c1_set_idx != c2_set_idx)) {
                if (sets[c2_set_idx].min < sets[c1_set_idx].min) {
                    sets[c1_set_idx].min = sets[c2_set_idx].min;
                }
                sets[c1_set_idx].equivalent.insert(sets[c2_set_idx].equivalent.begin(), sets[c2_set_idx].equivalent.end());
                sets.erase(sets.begin() + c2_set_idx);
            }
        }

        string result;

        for (int i = 0; i < baseStr.length(); ++i) {
            char c = baseStr[i];
            int set_idx = search_sets(sets, c);
            if (set_idx == -1) {
                result += c;
            } else {
                result += sets[set_idx].min;
            }
        }

        return result;
    }
};
