#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    class cmp {
        public:
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
            return a.second < b.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        unordered_map<int, int> count;
        for_each(nums.begin(), nums.end(), [&](int& elem) {
            count[elem]++;
        });
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        for_each(count.begin(), count.end(), [&](auto& elem) {
            pq.push(elem);
        });
        for (int i = 0; i < k; ++i) {
            result.push_back(pq.top().first);
            pq.pop();
        }
        return result;
    }
};
