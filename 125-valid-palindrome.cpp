#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string processed = "";
        if (s.size() == 1)
            return true;
        for (int i = 0; i < s.size(); ++i) {
            if (isalnum(s[i])) {
                processed += tolower(s[i]);
            }
        }
        int i = 0, j = processed.size()-1;
        while (i < j) {
            if (processed[i] != processed[j]) {
                return false;
            }
            ++i;
            --j;
        }
        return true;
    }
};
