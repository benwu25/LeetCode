#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        unordered_map<char, int> char_count_s, char_count_;
        for (int i = 0; i < s.size(); ++i) {
            char_count_s[s[i]]++;
            char_count_[t[i]]++;
        }
        return char_count_s == char_count_;
    }
};
