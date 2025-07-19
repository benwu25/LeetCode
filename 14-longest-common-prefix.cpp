#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = string("");
        while (1) {
            if (strs[0].size() <= prefix.size())
                return prefix;
            char next = strs[0][prefix.size()];
            for (int i = 1; i < strs.size(); ++i) {
                if (strs[i].size() <= prefix.size() || strs[i][prefix.size()] != next)
                    return prefix;
            }
            prefix += next;
        }
        return prefix;
    }
};
