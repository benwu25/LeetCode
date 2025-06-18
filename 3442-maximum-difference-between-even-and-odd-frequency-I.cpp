#include <string>
using namespace std;

class Solution {
public:
    int maxDifference(string s) {
        int alphabet[26];

        for (char c = 'a'; c <= 'z'; ++c) {
            alphabet[c - 'a'] = 0;
        }

        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            alphabet[c - 'a']++;
        }

        int even_min = s.size();
        int odd_max = 0;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (alphabet[c - 'a'] % 2 == 0) {
                even_min = (alphabet[c - 'a'] < even_min) ? alphabet[c - 'a'] : even_min;
            } else {
                odd_max = (alphabet[c - 'a'] > odd_max) ? alphabet[c - 'a'] : odd_max;
            }
        }
        int dif1 = odd_max - even_min;
        return dif1;
    }
};
