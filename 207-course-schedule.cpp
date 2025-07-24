#include <vector>
#include <unordered_map>
#include <deque>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int>());
        unordered_map<int, int> deg;
        for (auto& vec : prerequisites) {
            adj[vec[0]].push_back(vec[1]);
            deg[vec[1]]++;
        }
        for (int course = 0; course < numCourses; ++course) {
            if (!deg.count(course))
                deg[course] = 0;
        }
        deque<int> ready;
        for (auto& [node, degree] : deg) {
            if (degree == 0)
                ready.push_back(node);
        }
        int count = 0;
        while (ready.size()) {
            int next = ready.front(); ready.pop_front();
            ++count;
            for (auto& neighbor : adj[next]) {
                deg[neighbor]--;
                if (deg[neighbor] == 0)
                    ready.push_back(neighbor);
            }
        }
        return count == numCourses;
    }
};
