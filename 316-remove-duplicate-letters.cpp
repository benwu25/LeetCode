#include <string>
#include <unordered_map>
#include <unordered_set>
#include <deque>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> count;
        for (auto c : s) {
            count[c]++;
        }
        deque<char> strq;
        unordered_set<char> placed;
        for (int i = 0; i < s.size(); ++i) {
            if (placed.count(s[i])) {
                count[s[i]]--;
                continue;
            }
            while (strq.size() && strq.back() >= s[i] && count[strq.back()] > 1) {
                count[strq.back()]--;
                placed.erase(strq.back());
                strq.pop_back();
            }
            strq.push_back(s[i]);
            placed.insert(s[i]);
        }
        string res("");
        while (strq.size()) {
            res += strq.front();
            strq.pop_front();
        }
        return res;
    }
};
