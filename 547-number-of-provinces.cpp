#include <vector>
#include <deque>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_set<int> visited{};
        int count{0};
        for (int i = 0; i < isConnected.size(); ++i) {
            if (visited.count(i))
                continue;
            deque<int> ready{};
            ready.push_back(i);
            visited.insert(i);
            while (ready.size()) {
                int next = ready.front();
                ready.pop_front();
                // j = i+1
                for (int j = i+1; j < isConnected[next].size(); ++j) {
                    if (visited.count(j) || isConnected[next][j] == 0)
                        continue;
                    visited.insert(j);
                    ready.push_back(j);
                }
            }
            ++count;
        }
        return count;
    }
};
