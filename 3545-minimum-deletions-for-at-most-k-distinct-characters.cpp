#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minDeletion(string s, int k) {
        unordered_map<char, int> counts;
        for (int i = 0; i < s.size(); ++i) {
            counts[s[i]]++;
        }
        if (counts.size() <= k) return 0;
        vector<int> values;
        for_each(counts.begin(), counts.end(), [&](auto pair) {
            values.push_back(pair.second);
        });
        sort(values.begin(), values.end());
        int result = 0;
        for (int i = 0; i < counts.size() - k; ++i) {
            result += values[i];
        }
        return result;
    }


};
