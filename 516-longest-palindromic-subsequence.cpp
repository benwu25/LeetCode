#include <string>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int **best = new int*[s.size()];
        for (int i = 0; i < s.size(); ++i) {
            best[i] = new int[s.size()];
            best[i][i] = 1;
            if (i < s.size()-1) {
                best[i][i+1] = (s[i]==s[i+1]) ? 2 : 1;
            }
        }
        for (int diff = 2; diff <= s.size()-1; ++diff) {
            for (int i = 0, j = i+diff; j < s.size(); ++i, ++j) {
                if (s[i] == s[j]) {
                    best[i][j] = std::max(
                        std::max(best[i+1][j-1], best[i+1][j]),
                        std::max(best[i][j-1], 2+best[i+1][j-1])
                    );
                } else {
                    best[i][j] = std::max(
                        std::max(best[i+1][j-1], best[i+1][j]),
                        best[i][j-1]
                    );
                }
            }
        }
        int res = best[0][s.size()-1];
        for (int i = 0; i < s.size(); ++i) {
            delete[] best[i];
        }
        delete[] best;
        return res;
    }
};
