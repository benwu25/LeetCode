#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> color2balls;
        unordered_map<int, int> ball2color;
        vector<int> result;
        for (int i = 0; i < queries.size(); ++i) {
            vector<int>& query = queries[i];
            int ball = query[0];
            if (ball2color.count(ball)) {
                int old_color = ball2color[ball];
                int s = color2balls[old_color];
                if (s == 1) {
                    color2balls.erase(old_color);
                } else {
                    color2balls[old_color]--;
                }
            }
            ball2color[ball] = query[1];
            if (color2balls.count(query[1])) {
                color2balls[query[1]]++;
            } else {
                color2balls[query[1]] = 1;
            }
            result.push_back(color2balls.size());
        }
        return result;
    }
};
