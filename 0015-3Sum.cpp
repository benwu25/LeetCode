#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<int> sorted;
        vector<vector<int>> result;
        set<vector<int>> triples;
        std::copy(nums.begin(), nums.end(), std::back_inserter(sorted));
        std::sort(sorted.begin(), sorted.end());
        int N = sorted.size();
        set<int> visited;
        for (int i = 0; i < N; ++i) {
            if (visited.count(sorted[i]))
                continue;
            visited.insert(sorted[i]);
            twoSum(sorted, i+1, N, -sorted[i], triples);
        }
        std::copy(triples.begin(), triples.end(), std::back_inserter(result));
        return result;
    }

    void twoSum(vector<int>& numbers, int start, int end, int target, set<vector<int>>& results) {
        int i = start, j = end - 1;
        while (i < j) {
            if (numbers[i] + numbers[j] == target) {
                vector<int> triple;
                triple.push_back(numbers[i]);
                triple.push_back(numbers[j]);
                triple.push_back(-target);
                std::sort(triple.begin(), triple.end());
                results.insert(triple);
                ++i;
            } else if (numbers[i] + numbers[j] < target) {
                ++i;
            } else {
                --j;
            }
        }
    }
};
