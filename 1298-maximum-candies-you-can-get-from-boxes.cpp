#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    int maxCandies(vector<int>& status,
                   vector<int>& candies,
                   vector<vector<int>>& keys,
                   vector<vector<int>>& containedBoxes,
                   vector<int>& initialBoxes) {
        std::deque<int> ready_boxes;
        int *is_reachable = new int[status.size()];
        int *visited = new int[status.size()];

        for (int i = 0; i < status.size(); ++i) {
            is_reachable[i] = 0;
            visited[i] = 0;
        }

        for (int i = 0; i < initialBoxes.size(); ++i) {
            if (status[initialBoxes[i]] == 1) {
                ready_boxes.emplace_back(initialBoxes[i]);
                visited[initialBoxes[i]] = 1;
            }
            is_reachable[initialBoxes[i]] = 1;
        }

        int candy = 0;
        while (ready_boxes.size() > 0) {
            int box = ready_boxes.front();
            ready_boxes.pop_front();
            candy += candies[box];
            for (int i = 0; i < keys[box].size(); ++i) {
                int key = keys[box][i];
                status[key] = 1;
            }
            for (int i = 0; i < containedBoxes[box].size(); ++i) {
                int contained_box = containedBoxes[box][i];
                is_reachable[contained_box] = 1;
            }
            for (int i = 0; i < keys[box].size(); ++i) {
                int key = keys[box][i];
                if (is_reachable[key] == 1 && visited[key] == 0) {
                    ready_boxes.emplace_back(key);
                    visited[key] = 1;
                }
            }
            for (int i = 0; i < containedBoxes[box].size(); ++i) {
                int contained_box = containedBoxes[box][i];
                if (status[contained_box] == 1 && visited[contained_box] == 0) {
                    ready_boxes.emplace_back(contained_box);
                    visited[contained_box] = 1;
                }
            }
        }
        delete[] is_reachable;
        delete[] visited;
        return candy;
    }
};
