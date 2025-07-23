#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    class cmp {
        public:
        bool operator()(pair<string, int>& a, pair<string, int>& b) {
            if (a.second > b.second)
                return true;
            else if (a.second < b.second)
                return false;
            return a.first < b.first;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> count;
        for (auto& s : words) {
            count[s]++;
        }
        priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> pq;
        for (auto& p : count) {
            pq.push(p); // not pq.insert(p)
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<string> res;
        while (pq.size()) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};
