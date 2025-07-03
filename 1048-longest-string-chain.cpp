#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // a predecessor of b?
    bool check_predecessor(string& a, string& b) {
        if (a.size()+1 != b.size()) return false;
        for (int i = 0; i < b.size(); ++i) {
            if (a == b.substr(0, i) + b.substr(i+1))
                return true;
        }
        return false;
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](auto& elem1, auto& elem2) {
            return elem1.size() < elem2.size();
        });
        int *best = new int[words.size()];
        int tmp = 0;
        while (tmp < words.size() && words[tmp].size() == 1) {
            best[tmp] = 1;
            ++tmp;
        }
        for (int i = tmp; i < words.size(); ++i) {
            string curr = words[i];
            int mx = -1;
            for (int j = 0; j < i; ++j) {
                // if predecessor, update max
                if (check_predecessor(words[j], curr)) {
                    mx = max(mx, 1+best[j]);
                }
            }
            if (mx == -1) {
                best[i] = 1;
            } else {
                best[i] = mx;
            }
        }
        int mx = -1;
        for (int i = 0; i < words.size(); ++i) {
            mx = max(mx, best[i]);
        }
        return mx;
    }
};

/*

best[i] = max(
    1+best[i-k] where words[i-k] is a predecessor of words[i]
)

*/
