#include <vector>
#include <deque>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool bfs(int v, vector<vector<int>> &graph, unordered_set<int> &red, unordered_set<int> &blue, unordered_set<int> &visited) {
        deque<int> q{v};
        visited.insert(v);

        // choose red to start
        red.insert(v);

        while (q.size()) {
            int next = q.front();
            q.pop_front();

            bool is_red = (red.contains(next)) ? true : false;
            for (auto &neighbor : graph[next]) {
                if (is_red && red.contains(neighbor) || !is_red && blue.contains(neighbor))
                    return false;

                if (!visited.contains(neighbor)) {
                    if (is_red)
                        blue.insert(neighbor);
                    else
                        red.insert(neighbor);

                    visited.insert(neighbor);
                    q.push_back(neighbor);
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        unordered_set<int> red, blue, visited;
        for (int v = 0; v < graph.size(); ++v) {
            if (!visited.contains(v))
                if (!bfs(v, graph, red, blue, visited))
                    return false;
        }

        return true;
    }
};

/*
    perform bfs traversal

    for each node in bfs, check all neighbors.
    if any have been colored and match this node, return false.
    otherwise, color each unvisited (i.e., uncolored) node opposite from us.
*/
