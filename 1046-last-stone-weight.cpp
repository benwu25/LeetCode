#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> max_heap{};
        for (auto s : stones)
            max_heap.push(s);
        while (max_heap.size() > 1) {
            int s1 = max_heap.top();
            max_heap.pop();
            int s2 = max_heap.top();
            max_heap.pop();
            if (s1 > s2) {
                s1 -= s2;
                max_heap.push(s1);
                continue;
            }
            if (s1 < s2) {
                s2 -= s1;
                max_heap.push(s2);
                continue;
            }
            if (max_heap.size() == 0)
                return 0;
        }
        return max_heap.top();
    }
};
