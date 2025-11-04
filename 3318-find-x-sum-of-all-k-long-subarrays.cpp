#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct Cmp {
        bool operator()(pair<int, int> &a, pair<int, int> &b) {
            if (a.second != b.second)
                return a.second < b.second;
            return a.first < b.first;
        }
    };

    int xsum(vector<int> &nums, int i, int j, int x) {
        unordered_map<int, int> counts;
        for (; i <= j; ++i)
            counts[nums[i]]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp> pq(counts.begin(), counts.end());
        int sum = 0;
        while (x-- > 0 && pq.size()) {
            auto &next = pq.top();
            int freq = next.second;
            while (freq-- > 0)
                sum += next.first;
            pq.pop();
        }
        return sum;
    }

    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> result;
        for (int i = 0; i + k - 1 < nums.size(); ++i) {
            result.push_back(xsum(nums, i, i + k - 1, x));
        }
        return result;
    }
};
