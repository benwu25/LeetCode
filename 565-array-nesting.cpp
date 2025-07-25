#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int max = 1;
        vector<int> visited(nums.size(), 0);
        for (int i = 0; i < nums.size(); ++i) {
            if (visited[i] == 1)
                continue;
            deque<int> ready{};
            vector<int> path_count(nums.size(), 0);
            ready.push_back(i);
            visited[i] = 1;
            path_count[i] = 1;
            while (ready.size()) {
                int next = ready.front();
                ready.pop_back();
                if (visited[nums[next]] == 1) {
                    max = std::max(path_count[next], max);
                    continue;
                }
                path_count[nums[next]] = path_count[next] + 1;
                ready.push_back(nums[next]);
                visited[nums[next]] = 1;
            }
        }
        return max;
    }
};
