#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    class cmp {
        public:
            bool operator()(pair<char, int>& a, pair<char, int>& b) {
                return a.second < b.second;
            }
    };

    string reorganizeString(string s) {
        if (s.size() == 1)
            return s;
        unordered_map<char, int> count;
        for (auto& c : s) {
            count[c]++;
        }
        priority_queue<pair<char, int>, vector<pair<char, int>>, cmp> pq;
        for (auto p : count)
            pq.push(p);
        string res("");
        while (pq.size()) {
            pair<char, int> next = pq.top();
            pq.pop();
            if (pq.size()) {
                pair<char, int> x = pq.top();
                pq.pop();
                res += next.first;
                res += x.first;
                --next.second;
                --x.second;
                if (next.second > 0)
                    pq.push(next);
                if (x.second > 0)
                    pq.push(x);
            } else if (next.second == 1 && res[res.size()-1] != next.first) {
                return res + next.first;
            } else {
                return "";
            }
        }
        return res;
    }
};
