#include <queue>
using namespace std;

class Solution {
public:
    class cmp {
        public:
        bool operator()(int& a, int& b) {
            return a < b;
        }
    };
    int minStoneSum(vector<int>& piles, int k) {
        // put the piles in a priority queue, taking half from the top and reinserting, do k operations
        // then sum total stones left in the priority queue
        std::priority_queue<int, vector<int>, cmp> pq;
        for (auto i : piles) {
            pq.push(i);
        }
        for (int i = 0; i < k; ++i) {
            int next = pq.top();
            pq.pop();
            pq.push(next - next/2);
        }
        int total = 0;
        while (pq.size()) {
            total += pq.top();
            pq.pop();
        }
        return total;
    }
};
