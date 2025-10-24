#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool dfs(int v, vector<vector<int>> &adj, unordered_set<int> &red, unordered_set<int> &blue) {
        bool is_red = (red.contains(v)) ? true : false;

        for (auto &neighbor : adj[v]) {
            if (is_red && red.contains(neighbor) || !is_red && blue.contains(neighbor))
                return false;

            if (!red.contains(neighbor) && !blue.contains(neighbor)) {
                if (is_red)
                    blue.insert(neighbor);
                else
                    red.insert(neighbor);

                if (!dfs(neighbor, adj, red, blue))
                    return false;
            }
        }

        return true;
    }

    void build_adj(vector<vector<int>> &adj, vector<vector<int>> &dislikes) {
        for (auto &pair : dislikes) {
            adj[pair[0]].push_back(pair[1]);
            adj[pair[1]].push_back(pair[0]);
        }
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n + 1);
        build_adj(adj, dislikes);

        unordered_set<int> red, blue;

        for (int v = 1; v <= n; ++v) {
            if (!red.contains(v) && !blue.contains(v)) {
                // choose red to start
                red.insert(v);

                if (!dfs(v, adj, red, blue))
                    return false;
            }
        }

        return true;
    }
};
