#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool dfs(int v, vector<vector<int>> &graph, unordered_set<int> &red, unordered_set<int> &blue) {
        bool is_red = (red.contains(v)) ? true : false;

        for (auto &neighbor : graph[v]) {
            if (is_red && red.contains(neighbor) || !is_red && blue.contains(neighbor))
                return false;

            if (!red.contains(neighbor) && !blue.contains(neighbor)) {
                if (is_red)
                    blue.insert(neighbor);
                else
                    red.insert(neighbor);

                if (!dfs(neighbor, graph, red, blue))
                    return false;
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        unordered_set<int> red, blue;
        for (int v = 0; v < graph.size(); ++v) {
            if (!red.contains(v) && !blue.contains(v)) {
                // choose red to start
                red.insert(v);

                if (!dfs(v, graph, red, blue))
                    return false;
            }
        }

        return true;
    }
};
